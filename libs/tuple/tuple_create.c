/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:44:57 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/13 16:07:49 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tuple.h>

t_tuple	*new_tuple(double x, double y, double z, double w)
{
	t_tuple	*tuple;

	tuple = (t_tuple *)malloc(sizeof(t_tuple));
	if (!tuple)
		return (free(tuple), NULL);
	tuple->x = x;
	tuple->y = y;
	tuple->z = z;
	tuple->w = w;
	return (tuple);
}

t_point	*new_point(double x, double y, double z)
{
	return (new_tuple(x, y, z, 1.0));
}

t_vector	*new_vector(double x, double y, double z)
{
	return (new_tuple(x, y, z, 0.0));
}
