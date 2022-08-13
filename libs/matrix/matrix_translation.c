/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:28:55 by itaureli          #+#    #+#             */
/*   Updated: 2022/08/13 11:15:41 by itaureli         ###   ########.fr       */
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
