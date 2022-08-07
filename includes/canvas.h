/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:19:49 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/07 18:27:20 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>
# include <fcntl.h>

/**
 * @brief A struct to represent colors in RGB format.
*/
typedef struct s_color {
	double			r; // Red
	double			g; // Green
	double			b; // Blue
	unsigned int	rgb; // Decimal representation of the color
}	t_color;

typedef struct s_canvas {
	unsigned int	width;
	unsigned int	height;
	t_color			***pixels;
}	t_canvas;

typedef struct s_ppm {
	char	*header;
	char	*data;
}	t_ppm;

/**
 * @brief create and fill color struct
 * @param r red value
 * @param g green value
 * @param b blue value
 * @return t_color* color struct with all values filled
 */
t_color			*new_color(double r, double g, double b);

/**
 * @brief add two colors together
 * @param a first color struct
 * @param b second color struct
 * @return t_color* color struct result from values added
 */
t_color			*add_colors(t_color *a, t_color *b);

/**
 * @brief subtract two colors from each other
 * @param a first color struct
 * @param b second color struct
 * @return t_color* color struct result from values subtracted
 */
t_color			*subtract_colors(t_color *a, t_color *b);

/**
 * @brief multiply a color by a scalar value
 * @param c color struct
 * @param v scalar value
 * @return t_color* color struct result from values multiplied
 */
t_color			*multiply_scalar_color(t_color *c, double v);

/**
 * @brief multiply two colors together, blending them
 * @param a first color struct
 * @param b second color struct
 * @return t_color* color struct result from values multiplied
 */
t_color			*multiply_colors(t_color *a, t_color *b);

t_canvas		*new_canvas(int width, int height);

unsigned int	merge_colors(double r, double g, double b);
unsigned int	to_rgb(double c);

int				write_ppm(t_canvas *c, char *filename);

#endif
