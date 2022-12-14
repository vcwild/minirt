/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shape_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:30:43 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/06 18:36:51 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

static void	_intersect(t_shape *s, t_ray *r, t_intersections *xs, double t[2])
{
	double	y;

	if (t[0] > t[1])
		ft_swap((void *)t, (void *)&t[1], sizeof(double));
	y = r->origin->y + t[0] * r->direction->y;
	if (s->cylinder.min < y && y < s->cylinder.max)
		add_intersection(xs, new_intersection(t[0], s, OBJ_CYLINDER));
	y = r->origin->y + t[1] * r->direction->y;
	if (s->cylinder.min < y && y < s->cylinder.max)
		add_intersection(xs, new_intersection(t[1], s, OBJ_CYLINDER));
}

void	cylinder_intersect(t_shape *s, t_ray *r, t_intersections *xs)
{
	t_disc_coef	coef;
	double		disc;
	double		t[2];

	cylinder_intersect_caps(s, r, xs);
	coef.a = pow(r->direction->x, 2) + pow(r->direction->z, 2);
	if (dequals(coef.a, 0))
		return ;
	coef.b = 2 * r->origin->x * r->direction->x
		+ 2 * r->origin->z * r->direction->z;
	coef.c = pow(r->origin->x, 2) + pow(r->origin->z, 2) - 1;
	disc = coef.b * coef.b - 4 * coef.a * coef.c;
	if (disc < 0)
		return ;
	t[0] = (-coef.b - sqrt(disc)) / (2 * coef.a);
	t[1] = (-coef.b + sqrt(disc)) / (2 * coef.a);
	_intersect(s, r, xs, t);
}

t_vector	*get_cylinder_normal(t_shape *s, t_point *p)
{
	double	dist;

	dist = p->x * p->x + p->z * p->z;
	if (dist < 1 && p->y >= s->cylinder.max - EPSILON)
		return (new_vector(0, 1, 0));
	if (dist < 1 && p->y <= s->cylinder.min + EPSILON)
		return (new_vector(0, -1, 0));
	return (new_vector(p->x, 0, p->z));
}

void	destroy_cylinder(t_shape *s)
{
	destroy_shape(s);
}

t_shape	*new_cylinder(void)
{
	t_shape	*new;

	new = new_shape();
	new->cylinder.radius = 1;
	new->cylinder.position.w = 1;
	new->cylinder.min = -INFINITY;
	new->cylinder.max = INFINITY;
	new->cylinder.closed = false;
	new->get_normal = get_cylinder_normal;
	new->intersect = cylinder_intersect;
	new->destroy = destroy_cylinder;
	return (new);
}
