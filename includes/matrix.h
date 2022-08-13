/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:19:49 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/12 23:52:18 by itaureli         ###   ########.fr       */
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

/**
 * @brief The matrix structure. It has a size and a data[][] properties
 */
typedef struct s_matrix {
	int		size;
	double	data[MAT_INI_DIM][MAT_INI_DIM];
}	t_matrix;

/**
 * @brief Compare two given matrices
 * @param a Pointer to matrix a
 * @param b Pointer to matrix b
 * @return 1 if the matrices are equal, 0 otherwise
 */
int			matrix_equals(t_matrix *a, t_matrix *b);

/**
 * @brief Check if matrix is identity matrix (identity matrix is a matrix
 * with 1s on the diagonal)
 * @param mat
 * @return 1 if the matrix is identity matrix, 0 otherwise
 */

/**
 * @brief Check if a matrix is identity matrix (identity matrix is a
 * matrix with 1s on the diagonal)
 * @param mat Pointer to matrix
 * @return int 1 if the matrix is identity matrix, 0 otherwise
 */
int			matrix_is_identity(t_matrix *mat);

/**
 * @brief Check if the matrix is invertible, i.e. if its determinant is not 0
 * @param mat Pointer to matrix
 * @return int >0 if the matrix is invertible, 0 otherwise
 */
int			matrix_is_invertible(t_matrix *mat);

/**
* @brief Creates a new matrix with the given size
* @param size The size of the matrix
* @param mat Pointer to the new matrix to be created
* @return t_matrix* A new matrix with the given size
*/
t_matrix	*new_matrix(int size, double (*mat)[MAT_INI_DIM]);

/**
 * @brief Creates a new identity matrix (matrix with 1s on the diagonal)
 * @return t_matrix* Pointer to a new identity matrix
 */
t_matrix	*identity_matrix(void);

/**
 * @brief Create a new matrix reducing the given matrix by a number of rows and
 * columns
 * @param a Pointer to the matrix to be reduced
 * @param row The number of rows to be reduced
 * @param col The number of columns to be reduced
 * @return t_matrix* A new matrix with the given size
 */
t_matrix	*submatrix(t_matrix *a, int row, int col);

/**
 * @brief Create new matrix multiplying two given matrices
 * @param a Pointer to matrix a
 * @param b Pointer to matrix b
 * @return t_matrix* A new matrix with the result of the multiplication
 */
t_matrix	*matrix_multiply(t_matrix *a, t_matrix *b);

/**
 * @brief Multiply N given matrices
 * @param mats Pointer to the array of matrices
 * @return t_matrix* A new matrix with the result of the multiplication
 */
t_matrix	*matrix_multiply_n(t_matrix **mats);

/**
 * @brief Multiply 3 given matrices
 * @param a Pointer to matrix a
 * @param b Pointer to matrix b
 * @param c Pointer to matrix c
 * @return t_matrix* A new matrix with the result of the multiplication
 */
t_matrix	*matrix_multiply_3(t_matrix *a, t_matrix *b, t_matrix *c);

/**
 * @brief Create new tuple multiplying a matrix and a tuple
 * @param a Pointer to a matrix
 * @param b Pointer to a tuple
 * @return t_tuple* A tuple with the result of the multiplication
 */
t_tuple		*matrix_multiply_tuple(t_matrix *mat, t_tuple *t);

/**
 * @brief Calculate the determinant of a matrix (the determinant is the product
 * of the diagonal elements)
 * @param mat Pointer to the matrix to discover the determinant
 * @return double result of the determinant of the matrix
 */
double		matrix_determinant(t_matrix *mat);

/**
 * @brief Find the submatrix of a matrix with the given row and column and
 * calculate the determinant of it
 * @param mat Pointer to the matrix to discover the minor
 * @param row The row of the submatrix
 * @param col The column of the submatrix
 * @return double Result of the determinant of the submatrix
 */
double		minor(t_matrix *mat, int row, int col);

/**
 * @brief Check cofactor of a matrix, if row + column is a multiple of 2, then
 * negate the result, else return the result (minor of the matrix)
 * @param mat Pointer to the matrix to discover the cofactor
 * @param row The row of the cofactor
 * @param col The column of the cofactor
 * @return double Result of the cofactor of the matrix
 */
double		cofactor(t_matrix *mat, int row, int col);

/**
 * @brief
 *
 * @param mat Pointer to the matrix to be inverted
 * @return t_matrix*
 */
t_matrix	*invert(t_matrix *mat);

/**
 * @brief Transpose a matrix (swap rows and columns)
 * @param mat Pointer to the matrix to be transposed
 * @return t_matrix* A new matrix with the result of the transposition
 */
t_matrix	*transpose(t_matrix *mat);

#endif
