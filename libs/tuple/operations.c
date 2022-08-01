/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:45:01 by vwildner          #+#    #+#             */
/*   Updated: 2022/07/31 18:45:19 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tuple.h>

t_tuple	*add_tuples(t_tuple *a, t_tuple *b)
{
	return (new_tuple(a->x + b->x,
			a->y + b->y,
			a->z + b->z,
			a->w + b->w));
}

t_tuple	*subtract_tuples(t_tuple *a, t_tuple *b)
{
	return (new_tuple(a->x - b->x,
			a->y - b->y,
			a->z - b->z,
			a->w - b->w));
}

t_tuple	*negate_tuple(t_tuple *a)
{
	return (new_tuple(-a->x, -a->y, -a->z, -a->w));
}

t_tuple	*multiply_scalar(t_tuple *t, double v)
{
	return (new_tuple(t->x * v, t->y * v, t->z * v, t->w * v));
}

t_tuple	*divide_scalar(t_tuple *t, double v)
{
	return (new_tuple(t->x / v, t->y / v, t->z / v, t->w / v));
}
