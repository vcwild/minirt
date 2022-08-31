/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:01:03 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/31 14:11:01 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <camera.h>

void	set_camera_transform(t_camera *c, t_matrix *transform)
{
	free(c->transform);
	c->transform = transform;
}
