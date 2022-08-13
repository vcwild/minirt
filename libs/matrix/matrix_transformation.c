/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:28:55 by itaureli          #+#    #+#             */
/*   Updated: 2022/08/13 11:43:42 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_matrix	*translation(double x, double y, double z)
{
	t_matrix	*new;

	new = identity_matrix();
	new->data[0][3] = x;
	new->data[1][3] = y;
	new->data[2][3] = z;
	return (new);
}

t_matrix	*scaling(double x, double y, double z)
{
	t_matrix	*new;

	new = identity_matrix();
	new->data[0][0] = x;
	new->data[1][1] = y;
	new->data[2][2] = z;
	return (new);
}

t_matrix	*rotation_x(double radians)
{
	t_matrix	*new;

	new = identity_matrix();
	new->data[1][1] = cos(radians);
	new->data[1][2] = -sin(radians);
	new->data[2][1] = sin(radians);
	new->data[2][2] = cos(radians);
	return (new);
}

t_matrix	*rotation_y(double radians)
{
	t_matrix	*new;

	new = identity_matrix();
	new->data[0][0] = cos(radians);
	new->data[0][2] = sin(radians);
	new->data[2][0] = -sin(radians);
	new->data[2][2] = cos(radians);
	return (new);
}
