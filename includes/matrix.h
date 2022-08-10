/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:19:49 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/09 21:26:20 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

/* matrix default size*/
# define MAT_INI_DIM 4

# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>
# include <fcntl.h>
# include <tuple.h>

typedef struct s_matrix {
	int		size;
	double	data[4][4];
}	t_matrix;

int			matrix_equals(t_matrix *a, t_matrix *b);

t_matrix	*new_matrix(int size, double mat[4][4]);
t_matrix	*identity_matrix(void);
t_matrix	*submatrix(t_matrix *a, int row, int col);

double		cofactor(t_matrix *mat, int row, int col);
double		matrix_determinant(t_matrix *mat);

#endif
