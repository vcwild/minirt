/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:31:23 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/16 17:43:41 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <canvas.h>

t_color	*color_normalize(t_color *a)
{
	double	r;
	double	g;
	double	b;

	if (a->r > 0)
		r = a->r / 255;
	else
		r = 0;
	if (a->g > 0)
		g = a->g / 255;
	else
		g = 0;
	if (a->b > 0)
		b = a->b / 255;
	else
		b = 0;
	return (new_color(r, g, b));
}
