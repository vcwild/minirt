/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:56:01 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/18 14:41:12 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
int	main(void)
{
	t_rt_props		*props;
	t_rt			*rt;

	if (argc != 2)
		return (print_error("Wrong number of arguments"));
	if (!is_valid_extension(argv[1]))
		return (1);
	rt = new_ray_tracer(props);
	put_camera(rt);
	render_canvas(rt);
	run_mlx_window(rt);
	mlx_loop(rt->mlx);
	return (1);
  
	props = new_rt_props();
	if (load_scene(argv[1], props))
		return (1);
	rt = new_ray_tracer(props);
	destroy_rt_props(props);
	return (0);
}
