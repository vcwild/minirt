/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:43:05 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/20 20:43:09 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_matrix	*get_rotation_matrix(t_point *p)
{
	double		ratio;
	double		x;
	double		z;
	t_matrix	*angles[3];
	t_matrix	*rot;

	ratio = sqrt(p->x * p->x + p->y * p->y);
	if (ratio == 0)
		z = M_PI_2;
	else
		z = acos(p->y / ratio);
	x = acos(ratio);
	angles[0] = rotation_x(x);
	angles[1] = rotation_z(z);
	angles[2] = NULL;
	rot = matrix_multiply_n(angles);
	free(angles[0]);
	free(angles[1]);
	return (rot);
}
