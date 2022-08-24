/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:17:33 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/23 22:32:03 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <world.h>

t_color	*color_at(t_world *w, t_ray *r)
{
	t_intersections	*xs;
	t_intersection	*intersection;
	t_computations	*comps;
	t_color			*color;

	xs = intersect_world(w, r);
	intersection = hit(xs);
	if (intersection)
	{
		comps = prepare_computations(intersection, r);
		color = shade_hit(w, comps);
		destroy_intersections_list(xs);
		destroy_computations(comps);
		return (color);
	} else {
		destroy_intersections_list(xs);
		return (new_color(0, 0, 0));
	}
}
