/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:21:36 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/24 20:59:15 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tuple.h>

double	round_to(double num)
{
	return (round(num * pow(10, TUPLE_DECIMAL_PRECISION))
		/ pow(10, TUPLE_DECIMAL_PRECISION));
}

t_vector	*negate_tuple_free(t_vector *v)
{
	t_vector	*tmp;

	tmp = v;
	v = negate_tuple(v);
	free(tmp);
	return (v);
}
