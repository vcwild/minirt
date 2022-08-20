/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:19:49 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/20 06:19:56 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H
# define CANVAS_PPM_MAX_LINE_LENGTH 70

# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>

# include <tuple.h>
# include <libft.h>

/**
 * @brief A tuple to represent colors in RGB format.
 * Red, green, and blue and their respective merged components.
 */
typedef struct s_color {
	double			r;
	double			g;
	double			b;
	unsigned int	rgb;
}	t_color;

/**
 * @brief The canvas structure. It has a width and a height, and a pointer
 * to a matrix of colors that are called pixels.
 */
typedef struct s_canvas {
	unsigned int	width;
	unsigned int	height;
	t_color			***pixels;
}	t_canvas;

/**
 * @brief A ppm representation of a canvas.
 *
 * The ppm has a header and a data component.
 * The header has information about the width, height, and color depth.
 * The data has the actual pixels.
 */
typedef struct s_ppm {
	char			*header;
	unsigned int	*data;
}	t_ppm;

/**
 * @brief Creates a new color and fill struct.
 *
 * @param r The red component of the color.
 * @param g The green component of the color.
 * @param b The blue component of the color.
 * @return t_color* Returns a pointer to the new color struct.
 */
t_color			*new_color(double r, double g, double b);

/**
 * @brief Adds two colors together and returns the result.
 *
 * @param a The first color struct.
 * @param b The second color struct.
 * @return t_color* Returns a pointer to the result of the addition struct.
 */
t_color			*add_colors(t_color *a, t_color *b);

/**
 * @brief Adds two colors and then frees the original ones.
 *
 * @param a The first color struct.
 * @param b The second color struct.
 * @return t_color* Returns a pointer to the result of the addition struct.
 */
t_color	*add_colors_free_args(t_color *a, t_color *b);

/**
 * @brief Subtracts two colors
 *
 * @param a The first color struct.
 * @param b The second color struct.
 * @return t_color* Returns a pointer to the difference of the two colors struct
 */
t_color			*subtract_colors(t_color *a, t_color *b);

/**
 * @brief Multiplies a color by a scalar value.
 *
 * @param c The color struct to multiply.
 * @param v The scalar value.
 * @return t_color* Returns a pointer to the resulting color struct.
 */
t_color			*multiply_scalar_color(t_color *c, double v);

/**
 * @brief Multiplies two colors, blending them
 *
 * @param a The first color struct.
 * @param b The second color struct.
 * @return t_color* Returns a new color with the result of the multiplication
 */
t_color			*multiply_colors(t_color *a, t_color *b);

/**
 * @brief Creates a new instance of a canvas with each pixel set to black.
 *
 * @param width The width of the canvas.
 * @param height The height of the canvas.
 * @return t_canvas* Returns a pointer to the new canvas.
 */
t_canvas		*new_canvas(int width, int height);

/**
 * @brief Creates a merged integer representation of a color.
 *
 * @param r The float red component
 * @param g The float green component
 * @param b The float blue component
 * @return unsigned int Returns the merged integer representation
 */
unsigned int	merge_colors(double r, double g, double b);

/**
 * @brief Transforms a floating number to a 0 - 255 integer representation
 * RGB format.
 *
 * @param c The float number to transform.
 * @return unsigned int the transformed RGB value.
 */
unsigned int	to_rgb(double c);

/**
 * @brief Writes a PPM representation of the canvas to the given file.
 *
 * @param c The canvas to write.
 * @param filename The name of the file to write to.
 * @return int Returns 0 on success, > 0 on failure.
 */
int				write_ppm(t_canvas *c, char *filename);

/**
 * @brief Transforms a canvas into a PPM file representation.
 *
 * @param c The canvas to transform.
 * @return t_ppm* The PPM representation.
 */
t_ppm			*canvas_to_ppm(t_canvas *c);

/**
 * @brief write pixels into canvas
 *
 * @param c canvas struct to be used
 * @param width width position of pixel
 * @param height height position of pixel
 * @param color color of pixel
 * @return int 0 if successful, 1 if unsuccessful
 */
int				write_pixel(t_canvas *c,
					unsigned int width,
					unsigned int height,
					t_color *color);

/**
 * @brief get pixel color at specific position on canvas
 *
 * @param c canvas struct to be used
 * @param width width position of pixel
 * @param height height position of pixel
 * @return t_color* color of pixel or NULL if unsuccessful
 */
t_color			*pixel_at(t_canvas *c,
					unsigned int width,
					unsigned int height);

#endif
