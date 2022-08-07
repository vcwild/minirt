/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:44:52 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/06 19:42:19 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tuple.h>

int	is_point(t_tuple *t)
{
	return (t->w == 1.0);
}

int	is_vector(t_tuple *t)
{
	return (t->w == 0.0);
}

int	is_tuple(t_tuple *t)
{
	return (!is_vector(t) && !is_point(t));
}

int	dequals(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	return (0);
}

int	tuple_equals(t_tuple *a, t_tuple *b)
{
	return (dequals(a->x, b->x)
		&& dequals(a->y, b->y)
		&& dequals(a->z, b->z)
		&& dequals(a->w, b->w));
}
