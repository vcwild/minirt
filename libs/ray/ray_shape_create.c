/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shape_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:29:22 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/18 16:51:45 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

t_shape	*new_shape(void)
{
	t_shape	*shape;

	shape = (t_shape *)malloc(sizeof(t_shape));
	if (!shape)
		return (ft_err("Error\n new_shape malloc failed\n"), NULL);
	shape->transform = identity_matrix();
	shape->inverse_transform = identity_matrix();
	shape->material = new_material();
	shape->destroy = destroy_shape;
	shape->normalv = NULL;
	return (shape);
}

void	set_material(t_shape *s, t_material *mat)
{
	destroy_material(s->material);
	s->material = mat;
}
