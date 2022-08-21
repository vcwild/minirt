/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:19:12 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/21 12:34:14 by vwildner         ###   ########.fr       */
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
