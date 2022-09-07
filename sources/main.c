/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:56:01 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/07 20:13:42 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc)
{
	t_rt	*rt;

	if (argc != 2)
		return (ft_putstr_fd("Error: Wrong nb arguments", STDERR_FILENO), 1);
	rt = new_ray_tracer();
	destroy_ray_tracer(rt);
	return (0);
}
