/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:51:56 by itaureli          #+#    #+#             */
/*   Updated: 2022/09/17 16:20:44 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	t_color					*color;

	y = 0;
	while (y < canvas->height)
	{
		x = 0;
		while (x < canvas->width)
		{
			color = canvas->pixels[y][x];
			custom_mlx_put_pixel(image, x, y, color->rgb);
			x++;
		}
		y++;
	}
}

void	render_canvas(t_rt *rt)
{
	rt->canvas = render(rt->camera, rt->world);
	fill_mlx_image(rt->canvas, &rt->image);
	mlx_put_image_to_window(rt->mlx, rt->window, rt->image.img, 0, 0);
	return ;
}
