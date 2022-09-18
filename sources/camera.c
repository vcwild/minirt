/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:26:30 by itaureli          #+#    #+#             */
/*   Updated: 2022/09/18 10:28:38 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// TODO: Get values from, to, up from parser and place camera in the scene
void	put_camera(t_rt *rt)
{
	t_tuple	*from;
	t_tuple	*to;
	t_tuple	*up;

	from = new_point(0, 0, -5);
	to = new_point(0, 0, 0);
	up = new_vector(0, 1, 0);
	set_camera_transform(rt->camera, view_transform(from, to, up));
	free(from);
	free(to);
	free(up);
	return ;
}
