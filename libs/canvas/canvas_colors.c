/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:16:39 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/06 19:40:08 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <canvas.h>

t_color	*new_color(double r, double g, double b)
{
	t_color	*color;

	color = (t_color *)malloc(sizeof(t_color));
	color->r = r;
	color->g = g;
	color->b = b;
	color->rgb = merge_colors(r, g, b);
	return (color);
}

t_color	*add_colors(t_color *a, t_color *b)
{
	return (new_color(a->r + b->r, a->g + b->g, a->b + b->b));
}

t_color	*subtract_colors(t_color *a, t_color *b)
{
	return (new_color(a->r - b->r, a->g - b->g, a->b - b->b));
}

t_color	*multiply_scalar_color(t_color *c, double v)
{
	return (new_color(c->r * v, c->g * v, c->b * v));
}

t_color	*multiply_colors(t_color *a, t_color *b)
{
	return (new_color(a->r * b->r, a->g * b->g, a->b * b->b));
}
