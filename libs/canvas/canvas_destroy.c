/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:27:10 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/31 15:57:10 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <canvas.h>

void	destroy_canvas(t_canvas *c)
{
	unsigned int	width;
	unsigned int	height;

	height = 0;
	while (height < c->height)
	{
		width = 0;
		while (width < c->width)
		{
			free(c->pixels[height][width]);
			width++;
		}
		free(c->pixels[height]);
		height++;
	}
	free(c->pixels);
	free(c);
}
