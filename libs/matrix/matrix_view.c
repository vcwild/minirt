/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:55:27 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/25 18:26:47 by vwildner         ###   ########.fr       */
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
	free(orientation);
	if (!new)
		fprintf(stderr, "Error when translating view");
	return (new);
}

t_matrix	*view_transform(t_point *from, t_point *to, t_vector *up)
{
	t_matrix	*final;
	t_matrix	*orientation;
	t_point		*forward;
	t_tuple		*left;

	forward = normalize(up);
	left = cross(to, forward);
	free(forward);
	forward = cross(left, to);
	orientation = new_matrix(4, (double [4][4]){
		{left->x, left->y, left->z, 0},
		{forward->x, forward->y, forward->z, 0},
		{-to->x, -to->y, -to->z, 0},
		{0, 0, 0, 1},
		});
	final = translate_view(from, orientation);
	free(forward);
	free(left);
	return (final);
}
