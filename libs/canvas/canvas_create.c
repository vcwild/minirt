/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:55:28 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/18 16:48:38 by itaureli         ###   ########.fr       */
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
		ft_err("Error\n write_pixel out of bounds\n");
		return (1);
	}
	free(c->pixels[height][width]);
	c->pixels[height][width] = color;
	return (0);
}

t_color	*get_pixel(t_canvas *c, unsigned int width, unsigned int height)
{
	if (width > c->width || height > c->height)
	{
		ft_err("Error\n get_pixel out of bounds\n");
		return (NULL);
	}
	return (c->pixels[height][width]);
}
