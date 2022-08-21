/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:38:23 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/21 19:25:19 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <canvas.h>

unsigned int	to_rgb(double c)
{
	unsigned int	color;

	color = (unsigned int)round(c * 255);
	if (color > 255)
		color = 255;
	return (color);
}

unsigned int	merge_colors(double r, double g, double b)
{
	return (to_rgb(r) << 16 | to_rgb(g) << 8 | to_rgb(b));
}

t_color	*add_colors_free_args(t_color *a, t_color *b)
{
	t_color	*final;

	final = add_colors(a, b);
	free(a);
	free(b);
	return (final);
}
