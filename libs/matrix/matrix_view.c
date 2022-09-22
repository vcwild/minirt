/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:55:27 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/18 16:50:48 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_matrix	*translate_view(t_point *from, t_matrix *orientation)
{
	t_matrix	*new;
	t_matrix	*tmp;

	tmp = translation(-from->x, -from->y, -from->z);
	new = matrix_multiply(orientation, tmp);
	free(tmp);
	if (!new)
		ft_err("Error\n when translating view\n");
	return (new);
}

t_matrix	*view_transform(t_point *from, t_point *forward, t_vector *up)
{
	t_matrix	*final;
	t_matrix	*orientation;
	t_tuple		*tmp;
	t_tuple		*left;
	t_tuple		*true_up;

	tmp = subtract_tuples(forward, from);
	forward = normalize(tmp);
	free(tmp);
	up = normalize(up);
	left = cross(forward, up);
	true_up = cross(left, forward);
	free(up);
	orientation = new_matrix(4, (double [4][4]){
		{left->x, left->y, left->z, 0},
		{true_up->x, true_up->y, true_up->z, 0},
		{-forward->x, -forward->y, -forward->z, 0},
		{0, 0, 0, 1},
		});
	final = translate_view(from, orientation);
	free(orientation);
	free(true_up);
	free(left);
	free(forward);
	return (final);
}
