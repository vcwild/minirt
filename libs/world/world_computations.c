/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_computations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:26:12 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/04 10:20:50 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <world.h>

t_computations	*prepare_computations(t_intersection *x, t_ray *r)
{
	t_computations	*new;
	t_vector		*tmp;

	new = (t_computations *)malloc(sizeof(t_computations));
	new->t = x->t;
	new->object_type = x->object_type;
	new->shape = x->shape;
	new->point = get_position(r, new->t);
	new->eyev = negate_tuple(r->direction);
	new->normalv = get_normal(new->shape, new->point);
	new->inside = false;
	if (dot(new->normalv, new->eyev) < 0)
	{
		new->normalv = negate_tuple_free(new->normalv);
		new->inside = true;
	}
	tmp = multiply_scalar(new->normalv, EPSILON);
	new->over_point = add_tuples(new->point, tmp);
	free(tmp);
	return (new);
}
