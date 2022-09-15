/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:19:23 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/14 21:46:44 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rt	*new_ray_tracer(void)
{
	t_rt	*new;

	new = malloc(sizeof(t_rt));
	if (!new)
		return (NULL);
	new->mlx = mlx_init();
	new->window = mlx_new_window(new->mlx, RT_WIDTH, RT_HEIGHT, NAME);
	new->image.img = mlx_new_image(new->mlx, RT_WIDTH, RT_HEIGHT);
	new->image.addr = mlx_get_data_addr(new->image.img, &new->image.bpp,
			&new->image.line_length, &new->image.endian);
	new->world = default_world();
	new->camera = new_camera(RT_HEIGHT, RT_WIDTH, M_PI_2);
	return (new);
}

void	destroy_ray_tracer(t_rt *rt)
{
	destroy_world(rt->world);
	destroy_canvas(rt->canvas);
	destroy_camera(rt->camera);
	mlx_destroy_image(rt->mlx, rt->image.img);
	mlx_destroy_window(rt->mlx, rt->window);
	free(rt);
}
