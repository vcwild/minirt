/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:22:20 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/31 17:01:53 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <camera.h>

t_canvas	*render(t_camera *c, t_world *w)
{
	t_canvas		*image;
	t_ray			*ray;
	t_color			*color;
	unsigned int	width;
	unsigned int	height;

	image = new_canvas(c->hsize, c->vsize);
	height = 0;
	while (height < image->height)
	{
		width = 0;
		while (width < image->width)
		{
			ray = ray_for_pixel(c, width, height);
			color = get_color(w, ray);
			write_pixel(image, width, height, color);
			destroy_ray(ray);
			width++;
		}
		height++;
	}
	return (image);
}
