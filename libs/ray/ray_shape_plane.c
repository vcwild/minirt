/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shape_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:55:31 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/04 23:04:16 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

void	plane_intersect(t_shape *s, t_ray *r, t_intersections *xs)
{
	double			t;
	t_intersection	*new;

	if (fabs(r->direction->y) < EPSILON)
		return ;
	t = -r->origin->y / r->direction->y;
	new = new_intersection(t, s, OBJ_PLANE);
	add_intersection(xs, new);
}

t_vector	*get_plane_normal(t_shape *s, t_point *p)
{
	(void)p;
	(void)s;
	return (new_vector(0, 1, 0));
}

void	destroy_plane(t_shape *s)
{
	destroy_shape(s);
}

t_shape	*new_plane(void)
{
	t_shape		*shape;

	shape = new_shape();
	shape->plane.position = (t_point){0, 0, 0, 1};
	shape->get_normal = get_plane_normal;
	shape->intersect = plane_intersect;
	shape->destroy = destroy_plane;
	return (shape);
}
