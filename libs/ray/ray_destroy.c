/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:57:20 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/14 21:03:28 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

void	destroy_shape(t_shape *s)
{
	free(s->transform);
	free(s->inverse_transform);
	free(s);
}

void	destroy_sphere(t_shape *s)
{
	destroy_shape(s);
}

void	destroy_intersections_list(t_intersections *xs)
{
	while (xs->count--)
	{
		free(xs->intersections[xs->count]);
	}
	free(xs->intersections);
	free(xs);
}
