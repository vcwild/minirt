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

int	main(void)
{
	t_rt_props		*props;
	t_rt			*rt;

	props = new_rt_props();
	if (load_scene("./test.rt", props))
		return (1);
	rt = new_ray_tracer(props);
	destroy_rt_props(props);
	return (0);
}
