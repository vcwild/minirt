/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:27:55 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/12 18:58:05 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_matrix	*matrix_multiply(t_matrix *a, t_matrix *b)
{
	int			i;
	int			j;
	int			k;
	double		sum;
	t_matrix	*new;

	i = -1;
	new = new_matrix(a->size, NULL);
	while (++i < a->size)
	{
		j = -1;
		while (++j < a->size)
		{
			k = -1;
			sum = 0;
			while (++k < a->size)
				sum += a->data[i][k] * b->data[k][j];
			new->data[i][j] = sum;
		}
	}
	return (new);
}

t_matrix	*matrix_multiply_n(t_matrix **mats)
{
	t_matrix	*new;
	t_matrix	*tmp;
	int			i;

	i = -1;
	while (mats[++i])
		;
	tmp = mats[--i];
	while (i--)
	{
		new = matrix_multiply(mats[i], tmp);
		free(tmp);
		tmp = new;
	}
	return (new);
}

t_matrix	*matrix_multiply_3(t_matrix *a, t_matrix *b, t_matrix *c)
{
	t_matrix	**mats;
	t_matrix	*new;

	if (a->size != b->size || a->size != c->size || b->size != c->size)
		return (fprintf(stderr, "Error: matrix sizes do not match\n"), NULL);
	mats = (t_matrix **)malloc(sizeof(t_matrix *) * 3);
	mats[0] = a;
	mats[1] = b;
	mats[2] = c;
	new = matrix_multiply_n(mats);
	free(mats);
	return (new);
}

t_tuple	*matrix_multiply_tuple(t_matrix *mat, t_tuple *t)
{
	t_tuple	*new;
	double	tmp[MAT_INI_DIM];
	int		i;

	i = -1;
	while (++i < MAT_INI_DIM)
	{
		tmp[i] = mat->data[i][0] * t->x
			+ mat->data[i][1] * t->y
			+ mat->data[i][2] * t->z
			+ mat->data[i][3] * t->w;
	}
	new = new_tuple(tmp[0], tmp[1], tmp[2], tmp[3]);
	return (new);
}
