/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:19:49 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/01 21:52:07 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include <stddef.h>
# include <stdio.h>
# include <math.h>

typedef struct s_color {
	int	r;
	int	g;
	int	b;
}	t_color;

typedef union u_color {
	t_color	*color;
	void	*ptr;
}	t_maybe_color;

typedef struct s_canvas {
	unsigned int	width;
	unsigned int	height;
	t_color			***pixels;
}	t_canvas;

t_color		*new_color(double r, double g, double b);
t_color		*add_colors(t_color *a, t_color *b);
t_color		*subtract_colors(t_color *a, t_color *b);
t_color		*multiply_scalar_color(t_color *c, double v);
t_color		*multiply_colors(t_color *a, t_color *b);

t_canvas	*new_canvas(int width, int height);

#endif
