/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shape_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:55:31 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/14 16:10:14 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

t_vector	*get_sphere_normal(t_shape *shape, t_point *point)
{
	t_point	*normal;
	t_point	*center;

	(void)shape;
	center = new_point(0, 0, 0);
	normal = subtract_tuples(point, center);
	normal->w = 0;
	return (free(center), normal);
}

void	sphere_intersect(t_shape *s, t_ray *r, t_intersections *xs)
{
	t_disc_coef		coef;
	double			disc;
	double			t;
	t_intersection	*new;

	coef = (t_disc_coef){0, 0, 0};
	disc = get_discriminant((t_sphere *)s->props, r, &coef);
	if (disc < 0)
		return ;
	if (dequals(disc, 0))
		t = (-coef.b - sqrt(disc)) / (2 * coef.a);
	else
		t = (-coef.b + sqrt(disc)) / (2 * coef.a);
	new = new_intersection(t, s, OBJ_SPHERE);
	add_intersection(xs, new, OBJ_SPHERE);
}

t_sphere	*new_sphere_props(t_point *center, double radius)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		return (fprintf(stderr, "Error: new_sphere malloc failed\n"), NULL);
	sphere->center = center;
	sphere->radius = radius;
	return (sphere);
}

t_shape	*new_sphere(void)
{
	t_point		*center;
	t_shape		*shape;

	center = new_point(rand_double(), rand_double(), rand_double());
	shape = new_shape();
	shape->props = new_sphere_props(center, rand_double());
	shape->get_normal = get_sphere_normal;
	shape->intersect = sphere_intersect;
	return (shape);
}

void	destroy_sphere(t_shape *s)
{
	free(s->transform);
	free(s->inverse_transform);
	free(s->props->sphere->center);
	free(s->props->sphere);
	free(s->props);
	free(s);
}
