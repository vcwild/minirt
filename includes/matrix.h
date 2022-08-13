/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:19:49 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/12 19:55:57 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

/* matrix default size*/
# define MAT_INI_DIM 4

# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>

# include <tuple.h>
# include <libft.h>

typedef struct s_matrix {
	int		size;
	double	data[MAT_INI_DIM][MAT_INI_DIM];
}	t_matrix;

int			matrix_equals(t_matrix *a, t_matrix *b);
int			matrix_is_identity(t_matrix *mat);
int			matrix_is_invertible(t_matrix *mat);

t_matrix	*new_matrix(int size, double (*mat)[MAT_INI_DIM]);
t_matrix	*identity_matrix(void);
t_matrix	*submatrix(t_matrix *a, int row, int col);

t_matrix	*matrix_multiply(t_matrix *a, t_matrix *b);
t_matrix	*matrix_multiply_n(t_matrix **mats);
t_matrix	*matrix_multiply_3(t_matrix *a, t_matrix *b, t_matrix *c);
t_tuple		*matrix_multiply_tuple(t_matrix *mat, t_tuple *t);

double		matrix_determinant(t_matrix *mat);
double		minor(t_matrix *mat, int row, int col);
double		cofactor(t_matrix *mat, int row, int col);
t_matrix	*invert(t_matrix *mat);

t_matrix	*transpose(t_matrix *mat);

t_matrix	*matrix_translation(double x, double y, double z);
t_matrix	*matrix_scaling(double x, double y, double z);

t_matrix	*matrix_rotation_x(double angle);
t_matrix	*matrix_rotation_y(double angle);
t_matrix	*matrix_rotation_z(double angle);

#endif
