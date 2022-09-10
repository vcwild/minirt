/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 07:08:29 by itaureli          #+#    #+#             */
/*   Updated: 2022/09/10 07:08:46 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	close_window(t_rt *rt)
{
	destroy_ray_tracer(rt);
	exit(0);
	return (0);
}

static int	key_hook(int keycode, t_rt *rt)
{
	printf("get hook");
	if (keycode == KEY_ESC)
		close_window(rt);
	return (0);
}

int	key_hooks(t_rt *rt)
{
	mlx_hook(rt->window, EVENT_KEY_PRESS, 1L << 0, &key_hook, rt);
	mlx_hook(rt->window, EVENT_X_WIN_PRESS, 1L << 2, &close_window, rt);
	return (0);
}
