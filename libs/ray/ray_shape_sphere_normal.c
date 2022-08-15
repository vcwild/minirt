/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shape_sphere_normal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:28:38 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/15 20:33:29 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

t_vector	*get_sphere_normal(t_shape *shape, t_point *point)
{
	t_point	*normal;
	t_point	*center;

	(void)shape;
	center = new_point(0, 0, 0);
	normal = subtract_tuples(point, center);
	normal->w = 0;
	return (free(center), normal);
}
