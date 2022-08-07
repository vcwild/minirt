/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:19:49 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/07 19:15:46 by itaureli         ###   ########.fr       */
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

/**
 * @brief A struct to represent canvas in screen based on pixels.
 *
 */
typedef struct s_canvas {
	unsigned int	width; // Width of the canvas
	unsigned int	height; // Height of the canvas
	t_color			***pixels; // Color of each pixel in the canvas
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

/**
 * @brief Create canvas with each pixel set to black
 * @param width width of canvas
 * @param height height of canvas
 * @return t_canvas* created canvas struct
*/
t_canvas		*new_canvas(int width, int height);

unsigned int	merge_colors(double r, double g, double b);

/**
 * @brief convert given color to RGB format
 * @param c color float value
 * @return unsigned int RGB value
 */
unsigned int	to_rgb(double c);

int				write_ppm(t_canvas *c, char *filename);

/**
 * @brief write pixels into canvas
 * @param c canvas struct to be used
 * @param width width position of pixel
 * @param height height position of pixel
 * @param color color of pixel
 * @return int 0 if successful, 1 if unsuccessful
 */
int	write_pixel(t_canvas *c, unsigned int width, unsigned int height,
				t_color *color);

/**
 * @brief get pixel color at specific position on canvas
 * @param c canvas struct to be used
 * @param width width position of pixel
 * @param height height position of pixel
 * @return t_color* color of pixel or NULL if unsuccessful
 */
t_color	*pixel_at(t_canvas *c, unsigned int width, unsigned int height);
#endif
