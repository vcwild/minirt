/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:52:33 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/13 15:18:15 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_matrix	*matrix_rotation_x(double angle)
{
	t_matrix	*new;

	new = identity_matrix();
	new->data[1][1] = cos(angle);
	new->data[1][2] = -sin(angle);
	new->data[2][1] = sin(angle);
	new->data[2][2] = cos(angle);
	return (new);
}

t_matrix	*matrix_rotation_y(double angle)
{
	t_matrix	*new;

	new = identity_matrix();
	new->data[0][0] = cos(angle);
	new->data[0][2] = sin(angle);
	new->data[2][0] = -sin(angle);
	new->data[2][2] = cos(angle);
	return (new);
}

t_matrix	*matrix_rotation_z(double angle)
{
	t_matrix	*new;

	new = identity_matrix();
	new->data[0][0] = cos(angle);
	new->data[0][1] = -sin(angle);
	new->data[1][0] = sin(angle);
	new->data[1][1] = cos(angle);
	return (new);
}
