/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:19:12 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/24 23:11:31 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <world.h>

t_intersections	*intersect_world(t_world *w, t_ray *r)
{
	t_intersections	*xs;
	t_list			*tmp;

	xs = new_intersections_list();
	tmp = w->objects.spheres;
	while (tmp)
	{
		intersect((t_shape *)tmp->content, r, xs);
		tmp = tmp->next;
	}
	sort_intersections(xs);
	return (xs);
}

t_color	*get_color(t_world *w, t_ray *r)
{
	t_color			*color;
	t_computations	*comps;
	t_intersection	*x;
	t_intersections	*xs;

	xs = intersect_world(w, r);
	x = hit(xs);
	if (x == NULL)
	{
		destroy_intersections_list(xs);
		return (new_color(0, 0, 0));
	}
	comps = prepare_computations(x, r);
	color = shade_hit(w, comps);
	destroy_intersections_list(xs);
	free(comps->eyev);
	free(comps->normalv);
	free(comps);
	return (color);
}
