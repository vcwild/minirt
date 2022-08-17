/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:14:45 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/15 16:14:50 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

static void	handle_intersections_size(t_intersections *xs)
{
	t_intersection	**x;

	if (xs->count >= xs->size)
	{
		x = malloc(sizeof(t_intersection *) * (xs->size + RAY_XS_SIZE));
		ft_memmove(x, xs->intersections, sizeof(t_intersection *)
			* (xs->size));
		free(xs->intersections);
		xs->intersections = x;
		xs->size += RAY_XS_SIZE;
	}
}

void	add_intersection(t_intersections *xs, t_intersection *new)
{
	handle_intersections_size(xs);
	xs->intersections[xs->count] = new;
	xs->count++;
	xs->is_sorted = 0;
}

void	sort_intersections(t_intersections *xs)
{
	size_t			i;
	size_t			j;
	t_intersection	*tmp;

	if (xs->is_sorted)
		return ;
	i = -1;
	while (++i < xs->count)
	{
		j = i;
		while (++j < xs->count)
		{
			if (xs->intersections[i]->t > xs->intersections[j]->t)
			{
				tmp = xs->intersections[i];
				xs->intersections[i] = xs->intersections[j];
				xs->intersections[j] = tmp;
			}
		}
	}
	xs->is_sorted = 1;
}
