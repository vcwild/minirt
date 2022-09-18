/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:56:01 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/18 09:59:48 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_rt	*rt;

	if (argc != 2)
		return (print_error("Wrong number of arguments"));
	if (!is_valid_extension(argv[1]))
		return (1);
	rt = new_ray_tracer();
	render_canvas(rt);
	run_mlx_window(rt);
	mlx_loop(rt->mlx);
	return (1);
}
