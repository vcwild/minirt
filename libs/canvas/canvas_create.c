/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:55:28 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/06 19:27:40 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <canvas.h>

t_canvas	*new_canvas(int width, int height)
{
	t_canvas	*canvas;
	int			i;
	int			j;

	canvas = (t_canvas *)malloc(sizeof(t_canvas));
	canvas->width = width;
	canvas->height = height;
	canvas->pixels = (t_color ***)malloc(sizeof(t_color **) * height);
	i = 0;
	while (i < height)
	{
		canvas->pixels[i] = (t_color **)malloc(sizeof(t_color *) * width);
		j = 0;
		while (j < width)
		{
			canvas->pixels[i][j] = new_color(0.0, 0.0, 0.0);
			j++;
		}
		i++;
	}
	return (canvas);
}

int	write_pixel(t_canvas *c,
				unsigned int width,
				unsigned int height,
				t_color *color)
{
	if (width > c->width || height > c->height)
	{
		fprintf(stderr, "Error: write_pixel out of bounds\n");
		return (1);
	}
	c->pixels[height][width] = color;
	return (0);
}

t_color	*pixel_at(t_canvas *c, unsigned int width, unsigned int height)
{
	if (width > c->width || height > c->height)
	{
		fprintf(stderr, "Error: pixel_at out of bounds\n");
		return (NULL);
	}
	return (c->pixels[height][width]);
}
