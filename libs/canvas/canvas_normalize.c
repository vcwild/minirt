/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:31:23 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/15 20:05:08 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <canvas.h>

static double	color_dot(t_color *a, t_color *b)
{
	return (a->r * b->r + a->g * b->g + a->b * b->b);
}

static double	color_magnitude(t_color *a)
{
	return (sqrt(color_dot(a, a)));
}

static t_color	*color_multiply_scalar(t_color *c, double v)
{
	return (new_color(c->r * v, c->g * v, c->b * v));
}

t_color	*color_normalize(t_color *a)
{
	return (new_color(a->r / 255, a->g / 255, a->b / 255));
}
