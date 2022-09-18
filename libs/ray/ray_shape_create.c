/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shape_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:29:22 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/16 14:36:28 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

t_shape	*new_shape(void)
{
	t_shape	*shape;

	shape = (t_shape *)malloc(sizeof(t_shape));
	if (!shape)
		return (fprintf(stderr, "Error: new_shape failed"), NULL);
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
