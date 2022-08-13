/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:47:11 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/13 16:18:03 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

t_ray	*new_ray(t_point *origin, t_vector *direction)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (!ray)
		return (fprintf(stderr, "Error: new_ray malloc failed\n"), NULL);
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}
