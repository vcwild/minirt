/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:11:36 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/09 21:16:01 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

double	cofactor(t_matrix *mat, int row, int col);

double	matrix_determinant(t_matrix *mat)
{
	double	det;
	int		j;

	det = 0;
	j = -1;
	if (mat->size == 1)
		return (mat->data[0][0]);
	if (mat->size == 2)
		return (mat->data[0][0] * mat->data[1][1]
			- mat->data[0][1] * mat->data[1][0]);
	while (++j < mat->size)
		det += mat->data[0][j] * cofactor(mat, 0, j);
	return (det);
}
