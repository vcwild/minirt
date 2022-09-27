/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:26:30 by itaureli          #+#    #+#             */
/*   Updated: 2022/09/18 17:38:22 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_camera(t_rt *rt, t_rt_props *props)
{
	t_tuple		*up;
	t_matrix	*transform;

	up = new_vector(0, 1, 0);
	transform = view_transform(props->c->origin, props->c->direction, up);
	set_camera_transform(rt->camera, transform);
	free(up);
	return ;
}
