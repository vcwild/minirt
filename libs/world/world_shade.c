/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_shade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:51:39 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/21 22:19:04 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <world.h>

t_ray	*get_ray(t_point *p, t_vector *target)
{
	t_vector	*v;
	t_vector	*dir;
	t_ray		*new;

	v = subtract_tuples(target, p);
	dir = normalize(v);
	new = new_ray(p, dir);
	free(v);
	free(dir);
	return (new);
}

bool	is_shadowed(t_world *w, t_point *p, t_point_light *pl)
{
	t_vector		*v;
	double			dist;
	t_ray			*ray;
	t_intersections	*xs;
	bool			is_shadowed;

	is_shadowed = false;
	v = subtract_tuples(pl->position, p);
	dist = magnitude(v);
	ray = get_ray(p, pl->position);
	xs = intersect_world(w, ray);
	if (hit(xs) && (hit(xs)->t < dist))
		is_shadowed = true;
	free(v);
	destroy_ray(ray);

	// seg fault here
	// destroy_intersections_list(xs);
	return (is_shadowed);
}

t_color	*sum_colors(t_list *colors)
{
	t_color	*sum;

	sum = add_colors_free_args(new_color(0, 0, 0), colors->content);
	colors = colors->next;
	while (colors)
	{
		sum = add_colors_free_args(sum, colors->content);
		colors = colors->next;
	}
	return (sum);
}

t_color	*shade_hit(t_world *w, t_computations *c)
{
	t_lighting_args	args;
	t_list			*tmp;
	t_color			*final;
	t_list			*colors;

	args.material = c->shape->material;
	args.position = c->point;
	args.normal_vector = c->normalv;
	args.eye_vector = c->eyev;
	tmp = w->lights;
	colors = NULL;
	while (tmp)
	{
		args.lighting = tmp->content;
		args.in_shadow = is_shadowed(w, c->point, tmp->content);
		ft_lstadd_front(&colors, ft_lstnew(lighting(&args)));
		tmp = tmp->next;
	}
	final = sum_colors(colors);

	// final return exact 0.3 up to expected...
	printf("colors: %lf %lf %lf\n", final->r, final->g, final->b);
	return (final);
}
