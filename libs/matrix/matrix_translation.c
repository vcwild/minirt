/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:29:32 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/13 15:18:47 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_matrix	*matrix_translation(double x, double y, double z)
{
	t_matrix	*new;

	new = identity_matrix();
	new->data[0][3] = x;
	new->data[1][3] = y;
	new->data[2][3] = z;
	return (new);
}

t_matrix	*matrix_scaling(double x, double y, double z)
{
	t_matrix	*new;

	new = identity_matrix();
	new->data[0][0] = x;
	new->data[1][1] = y;
	new->data[2][2] = z;
	return (new);
}
