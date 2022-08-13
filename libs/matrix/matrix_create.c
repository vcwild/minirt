/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:20:57 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/12 12:26:13 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_matrix	*new_matrix(int size, double (*mat)[MAT_INI_DIM])
{
	t_matrix	*new;

	new = (t_matrix *) malloc(sizeof(t_matrix));
	if (!new)
		return (fprintf(stderr, "Error: matrix allocation failed\n"), NULL);
	new->size = size;
	if (!mat)
		return (new);
	ft_memcpy(new->data, mat, sizeof(double) * MAT_INI_DIM * MAT_INI_DIM);
	return (new);
}

t_matrix	*identity_matrix(void)
{
	double	mat[MAT_INI_DIM][MAT_INI_DIM];
	int		i;
	int		j;

	i = -1;
	while (++i < MAT_INI_DIM)
	{
		j = -1;
		while (++j < MAT_INI_DIM)
		{
			mat[i][j] = 0;
			if (i == j)
				mat[i][j] = 1;
		}
	}
	return (new_matrix(MAT_INI_DIM, mat));
}

t_matrix	*submatrix(t_matrix *a, int row, int col)
{
	int			i;
	int			j;
	t_matrix	*new;

	new = new_matrix(a->size - 1, NULL);
	i = -1;
	while (++i < a->size)
	{
		j = -1;
		while (++j < a->size)
			new->data[i][j] = a->data[i + (i >= row)][j + (j >= col)];
	}
	return (new);
}
