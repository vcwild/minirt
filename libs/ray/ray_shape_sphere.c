/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shape_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:55:31 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/04 16:24:44 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

void	sphere_intersect(t_shape *s, t_ray *r, t_intersections *xs)
{
	t_disc_coef		coef;
	double			disc;
	double			t;
	t_intersection	*new;

	coef = (t_disc_coef){0, 0, 0};
	disc = get_discriminant(&s->sphere, r, &coef);
	if (disc < 0)
		return ;
	t = (-coef.b - sqrt(disc)) / (2 * coef.a);
	new = new_intersection(t, s, OBJ_SPHERE);
	add_intersection(xs, new);
	if (dequals(disc, 0))
		return ;
	t = (-coef.b + sqrt(disc)) / (2 * coef.a);
	new = new_intersection(t, s, OBJ_SPHERE);
	add_intersection(xs, new);
}

t_shape	*new_sphere(void)
{
	t_shape		*shape;

	shape = new_shape();
	shape->sphere.center = (t_point){0, 0, 0, 1.0};
	shape->sphere.radius = 1.0;
	shape->get_normal = get_sphere_normal;
	shape->intersect = sphere_intersect;
	shape->destroy = destroy_sphere;
	return (shape);
}

void	set_transform(t_shape *s, t_matrix *mat)
{
	free(s->transform);
	s->transform = mat;
	free(s->inverse_transform);
	s->inverse_transform = invert(mat);
}

void	intersect(t_shape *shape, t_ray *r, t_intersections *xs)
{
	t_ray	*tmp_ray;

	tmp_ray = transform(r, shape->inverse_transform);
	shape->intersect(shape, tmp_ray, xs);
	destroy_ray(tmp_ray);
}
