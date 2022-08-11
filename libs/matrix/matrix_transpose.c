/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:44:03 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/10 20:55:23 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_matrix	*transpose(t_matrix *mat)
{
	t_matrix	*new;
	int			i;
	int			j;

	new = new_matrix(mat->size, NULL);
	i = -1;
	while (++i < mat->size)
	{
		j = -1;
		while (++j < mat->size)
			new->data[j][i] = mat->data[i][j];
	}
	return (new);
}
