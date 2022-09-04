/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_shade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:51:39 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/04 10:43:35 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <world.h>

t_ray	*get_ray(t_point *p, t_vector *target)
{
	t_vector	*v;
	t_vector	*dir;
	t_point		*p_new;
	t_ray		*new;

	p_new = new_point(p->x, p->y, p->z);
	v = subtract_tuples(target, p);
	dir = normalize(v);
	new = new_ray(p_new, dir);
	free(v);
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
	destroy_ray(ray);
	free(v);
	destroy_intersections_list(xs);
	return (is_shadowed);
}

t_color	*sum_colors(t_list *colors)
{
	t_color	*sum;
	t_color	*new;

	new = new_color(0, 0, 0);
	sum = add_colors(new, colors->content);
	free(new);
	ft_lstclear(&colors, free);
	return (sum);
}

t_color	*shade_hit(t_world *w, t_computations *c)
{
	t_lighting_args	*args;
	t_position_args	*pos_args;
	t_color			*final;

	pos_args = new_position_args(c->point, c->normalv, c->eyev);
	args = new_light_args(c->shape->material, w->lights->content, pos_args);
	args->in_shadow = is_shadowed(w, c->over_point, w->lights->content);
	final = lighting(args);
	free(args);
	return (final);
}
