/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:19:49 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/06 19:49:27 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>

typedef struct s_color {
	double			r;
	double			g;
	double			b;
	unsigned		int	rgb;
}	t_color;

typedef struct s_canvas {
	unsigned int	width;
	unsigned int	height;
	t_color			***pixels;
}	t_canvas;

t_color			*new_color(double r, double g, double b);
t_color			*add_colors(t_color *a, t_color *b);
t_color			*subtract_colors(t_color *a, t_color *b);
t_color			*multiply_scalar_color(t_color *c, double v);
t_color			*multiply_colors(t_color *a, t_color *b);

t_canvas		*new_canvas(int width, int height);

unsigned int	merge_colors(double r, double g, double b);

#endif
