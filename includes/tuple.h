/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:40:13 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/13 16:16:29 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# define EPSILON 0.0000001
# define TUPLE_DECIMAL_PRECISION 5

# include <stdlib.h>
# include <math.h>

/**
 * Stores a tuple for 3D space.
 * x axis pointing to the right
 * y axis point up
 * z axis pointing out of the screen
 * w defines if the tuple is a point, vector or tuple
*/
struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
};

/* type aliases, only used for typing convenience */
typedef struct s_tuple	t_tuple;
typedef struct s_tuple	t_point;
typedef struct s_tuple	t_vector;

/**
 * @brief create a new tuple
 * based on the given x, y, z values
 * @param x x axis value
 * @param y y axis value
 * @param z z axis value
 * @param w w type of the tuple
 * @return a pointer to tuple created
 */
t_tuple		*new_tuple(double x, double y, double z, double w);

/**
 * @brief create a point tuple (w = 1.0)
 * based on the given x, y, z values
 * @param x x axis value
 * @param y y axis value
 * @param z z axis value
 * @return a pointer to tuple created
 */
t_point		*new_point(double x, double y, double z);

/**
 * @brief create a vector tuple  (w = 0.0)
 * based on the given x, y, z values
 * @param x x axis value
 * @param y y axis value
 * @param z z axis value
 * @return a pointer to tuple created
 */
t_vector	*new_vector(double x, double y, double z);

/**
 * @brief check if tuple is a point
 * tuple is a point if w is 1.0
 * @param t tuple to be checked
 * @return true if tuple is a point, false otherwise
 */
int			is_point(t_tuple *t);

/**
 * @brief check if tuple is a vector
 * tuple is a vector if w is 0.0
 * @param t tuple to be checked
 * @return true if tuple is a vector, false otherwise
 */
int			is_vector(t_tuple *t);

int			is_tuple(t_tuple *t);

/**
 * @brief check if two doubles are equals
 * using the EPSILON value to avoid rounding errors
 * @param a first double to be compared
 * @param b second double to be compared
 * @return true if equals, false otherwise
 */
int			dequals(double a, double b);

/**
 * @brief check if two tuples are equals
 * using the dequals function
 * @param a first tuple to be compared
 * @param b second tuple to be compared
 * @return true if equals, false otherwise
 */
int			tuple_equals(t_tuple *a, t_tuple *b);

/**
 * @brief make a new tuple that is the sum of two tuples,
 * this allow you to know where you would be if you followed
 * the vector from that point
 * @param a first tuple to be added
 * @param b second tuple to be added
 * @return a pointer to the new tuple
 */
t_tuple		*add_tuples(t_tuple *a, t_tuple *b);

/**
 * @brief make a new tuple that is the difference of two tuples,
 * this allow you to know where you would be if you followed
 * the vector from that point. Useful when you need to find
 * the vector that points to your light source
 * @param a first tuple to be subtracted
 * @param b second tuple to be subtracted
 * @return a pointer to the new tuple
 */
t_tuple		*subtract_tuples(t_tuple *a, t_tuple *b);

/**
 * @brief invert the sign of the tuple values
 * to get the opposite vector
 * @param a tuple to have values inverted
 * @return a pointer to the inverted tuple
 */
t_tuple		*negate_tuple(t_tuple *a);

/**
 * @brief multiply a tuple by a scalar values
 * to get uniform scaling
 * @param t tuple to be multiplied
 * @param v scalar value
 * @return the tuple values multiplied by the scalar value
 */
t_tuple		*multiply_scalar(t_tuple *t, double v);

/**
 * @brief divide a tuple by a scalar values
 * to get uniform scaling
 * @param t tuple to be divided
 * @param v scalar value
 * @return the tuple values divided by the scalar value
 */
t_tuple		*divide_scalar(t_tuple *t, double v);

/**
 * @brief calculate the angle between two vectors
 * @param a first tuple
 * @param b second tuple
 * @return double scalar value of the angle between the two vectors
 */
double		dot(t_tuple *a, t_tuple *b);

/**
 * @brief calculate magnitude of a vector, it's
 * how far it is from the origin
 * @param a tuple to be calculated
 * @return magnitude of the vector
 */
double		magnitude(t_tuple *a);

/**
 * @brief normalize a vector, it's
 * make the vector have a magnitude of 1.0 (unit vector)
 * @param a tuple to be normalized
 * @return a pointer to the normalized tuple
 */
t_tuple		*normalize(t_tuple *a);

/**
 * @brief calculate the cross product of two vectors
 * @param a first tuple
 * @param b seconde tuple
 * @return t_tuple* vector that is the cross product of the two tuples
 */
t_tuple		*cross(t_tuple *a, t_tuple *b);

t_tuple		*reflect(t_tuple *v, t_tuple *n);
double		round_to(double num);

#endif
