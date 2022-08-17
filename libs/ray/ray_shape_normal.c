/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shape_normal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:13:05 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/16 23:12:06 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

t_vector	*get_normal(t_shape *shape, t_point *world_point)
{
	t_tuple		*world_normal;
	t_tuple		*normal;
	t_point		*point;
	t_tuple		*tmp_normal;
	t_matrix	*transposed_inverse;

	point = matrix_multiply_tuple(shape->inverse_transform, world_point);
	normal = shape->get_normal(shape, point);
	transposed_inverse = transpose(shape->inverse_transform);
	tmp_normal = matrix_multiply_tuple(transposed_inverse, normal);
	tmp_normal->w = 0;
	free(transposed_inverse);
	free(normal);
	free(point);
	world_normal = normalize(tmp_normal);
	free(tmp_normal);
	return (world_normal);
}
