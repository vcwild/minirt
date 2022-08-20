/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shape_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:29:22 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/20 04:50:56 by vwildner         ###   ########.fr       */
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
	return (shape);
}
