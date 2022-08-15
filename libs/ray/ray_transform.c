/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:39:31 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/14 22:42:03 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

t_ray	*transform(t_ray *r, t_matrix *mat)
{
	t_point	*new_origin;
	t_point	*new_direction;

	new_origin = matrix_multiply_tuple(mat, r->origin);
	new_direction = matrix_multiply_tuple(mat, r->direction);
	return (new_ray(new_origin, new_direction));
}
