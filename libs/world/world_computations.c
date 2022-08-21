/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_computations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:26:12 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/21 15:40:44 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <world.h>

t_computations	*prepare_computations(t_intersection *x, t_ray *r)
{
	t_computations	*new;

	new = (t_computations *)malloc(sizeof(t_computations));
	new->t = x->t;
	new->object_type = x->object_type;
	new->shape = x->shape;
	new->point = get_position(r, new->t);
	new->eyev = negate_tuple(r->direction);
	new->normalv = get_normal(new->shape, new->point);
	return (new);
}
