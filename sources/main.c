/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:56:01 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/17 15:15:04 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc)
{
	t_rt	*rt;

	if (argc != 2)
		return (ft_putstr_fd("Error \n Wrong number of arguments",
				STDERR_FILENO), 1);
	rt = new_ray_tracer();
	render_canvas(rt);
	run_mlx_window(rt);
	mlx_loop(rt->mlx);
	return (0);
}
