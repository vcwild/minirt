/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:47:11 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/18 16:51:09 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

t_ray	*new_ray(t_point *origin, t_vector *direction)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (!ray)
		return (ft_err("Error\n new_ray malloc failed\\n"), NULL);
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}

t_point	*get_position(t_ray *ray, double distance)
{
	t_tuple	*tmp;
	t_point	*new;

	tmp = multiply_scalar(ray->direction, distance);
	new = add_tuples(ray->origin, tmp);
	free(tmp);
	return (new);
}
