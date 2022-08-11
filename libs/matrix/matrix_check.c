/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:25:23 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/10 21:18:38 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

int	matrix_equals(t_matrix *a, t_matrix *b)
{
	int	i;
	int	j;

	if (a->size != b->size)
		return (0);
	i = -1;
	while (++i < a->size)
	{
		j = -1;
		while (++j < a->size)
		{
			if (!dequals(a->data[i][j], b->data[i][j]))
				return (0);
		}
	}
	return (1);
}

int	matrix_is_square(t_matrix *mat)
{
	return (mat->size == mat->size);
}

int	matrix_is_identity(t_matrix *mat)
{
	int	i;
	int	j;

	if (!matrix_is_square(mat))
		return (0);
	i = -1;
	while (++i < mat->size)
	{
		j = -1;
		while (++j < mat->size)
		{
			if (i == j && mat->data[i][j] != 1)
				return (0);
			if (i != j && mat->data[i][j] != 0)
				return (0);
		}
	}
	return (1);
}

int	matrix_is_invertible(t_matrix *mat)
{
	return (matrix_determinant(mat) != 0);
}
