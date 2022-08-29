/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:21:17 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/29 20:50:20 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <camera.h>

t_camera	*new_camera(double hsize, double vsize, double fov)
{
	t_camera	*new;
	double		aspect;

	new = (t_camera *)malloc(sizeof(t_camera));
	if (!new)
		return (fprintf(stderr, "Error: Failed creating a camera!"), NULL);
	new->hsize = hsize;
	new->vsize = vsize;
	new->fov = fov;
	new->transform = identity_matrix();
	aspect = hsize / vsize;
	new->half_width = tan(fov / 2);
	new->half_height = new->half_width / aspect;
	if (aspect < 1)
	{
		new->half_height = tan(fov / 2);
		new->half_width = new->half_height * aspect;
	}
	new->pixel_size = (new->half_width * 2) / hsize;
	return (new);
}
