/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:51:56 by itaureli          #+#    #+#             */
/*   Updated: 2022/09/12 21:19:39 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	run_mlx_window(t_rt *rt)
{
	key_hooks(rt);
}

void	custom_mlx_put_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

void	fill_mlx_image(t_canvas *canvas, t_image *image)
{
	unsigned int			x;
	unsigned int			y;
	unsigned int			color;

	y = 0;
	while (y < canvas->height)
	{
		x = 0;
		while (x < canvas->width)
		{
			color = canvas->pixels[y * canvas->width + x];
			custom_mlx_put_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
}

/*
void draw_pixels(t_rt *rt)
{
	int color = 0x0F9999;
	int color2 = 0xFF0F0F;
	int *buffer;

	buffer = (int *)rt->image.addr;
	rt->image.line_length /= 4;

	for(int y = 0; y < RT_HEIGHT; ++y)
	for(int x = 0; x < RT_WIDTH; ++x)
	{
		int pixel = (y * rt->image.line_length) + (x);
		buffer[pixel] = (x % 2 == 0) ? color : color2;
	}
}
*/

void	render_canvas(t_rt *rt)
{
	rt->canvas = render(rt->world, rt->camera);
	fill_mlx_image(rt->canvas, &rt->image);
	mlx_put_image_to_window(rt->mlx, rt->window, rt->image.img, 0, 0);
	return ;
}
