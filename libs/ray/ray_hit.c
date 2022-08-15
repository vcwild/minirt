/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:44:58 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/14 21:59:39 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

t_intersection	*hit(t_intersections *xs)
{
	t_intersection	*first_hit;
	size_t			i;

	i = 0;
	first_hit = NULL;
	if (!xs->is_sorted)
		sort_intersections(xs);
	while (i < xs->count)
	{
		first_hit = xs->intersections[i];
		if (first_hit->t > 0)
			return (first_hit);
		i++;
	}
	return (NULL);
}
