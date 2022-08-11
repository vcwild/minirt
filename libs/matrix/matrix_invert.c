/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:11:36 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/10 21:04:15 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

double	matrix_determinant(t_matrix *mat);

double	minor(t_matrix *mat, int row, int col)
{
	t_matrix	*new;
	double		min;

	new = submatrix(mat, row, col);
	min = matrix_determinant(new);
	free(new);
	return (min);
}

double	cofactor(t_matrix *mat, int row, int col)
{
	double	min;

	min = minor(mat, row, col);
	if ((row + col) % 2 != 0)
		min *= -1;
	return (min);
}

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

t_matrix	*invert(t_matrix *mat)
{
	t_matrix	*new;
	int			i;
	int			j;
	double		det;
	double		cof;

	if (!matrix_is_invertible(mat))
		return (NULL);
	det = matrix_determinant(mat);
	new = new_matrix(mat->size, NULL);
	i = -1;
	while (++i < mat->size)
	{
		j = -1;
		while (++j < mat->size)
		{
			cof = cofactor(mat, i, j);
			new->data[j][i] = cof / det;
		}
	}
	return (new);
}
