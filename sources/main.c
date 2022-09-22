/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:56:01 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/21 21:20:39 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_rt_props		*props;
	t_rt			*rt;

	if (argc != 2)
		return (ft_err("Error\n Wrong number of arguments"), 1);
	if (!is_valid_extension(argv[1]))
		return (1);
	props = new_rt_props();
	if (load_scene(argv[1], props))
		return (1);
	rt = new_ray_tracer(props);
	put_camera(rt, props);
	render_canvas(rt);
	run_mlx_window(rt);
	mlx_loop(rt->mlx);
	destroy_rt_props(props);
	return (0);
}
