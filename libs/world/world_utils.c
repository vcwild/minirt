/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:17:33 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/23 21:58:31 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <world.h>

t_color	*color_at(t_world *w, t_ray *r)
{
	// get intersection of the given ray
	t_intersections	*xs;
	t_color			*color;

	xs = intersect_world(w, r);
	if (hit(xs))
	{
		// get the color at the point of intersection
		// color = shade_hit(...);
		destroy_intersections_list(xs);
		return (color);
	}
	else
	{
		// free the intersection list and return black
		destroy_intersections_list(xs);
		return (new_color(0, 0, 0));
	}
}
