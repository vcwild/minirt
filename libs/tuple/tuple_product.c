/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:44:48 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/06 18:54:35 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tuple.h>

double	dot(t_tuple *a, t_tuple *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w);
}

double	magnitude(t_tuple *a)
{
	return (round_to(sqrt(dot(a, a))));
}

t_tuple	*normalize(t_tuple *a)
{
	return (multiply_scalar(a, round_to(1.0 / magnitude(a))));
}

t_tuple	*cross(t_tuple *a, t_tuple *b)
{
	return (new_vector(a->y * b->z - a->z * b->y,
			a->z * b->x - a->x * b->z,
			a->x * b->y - a->y * b->x));
}

t_tuple	*reflect(t_tuple *v, t_tuple *n)
{
	t_tuple	*doubled;
	t_tuple	*subtracted;

	doubled = multiply_scalar(n, 2.0 * dot(v, n));
	subtracted = subtract_tuples(v, doubled);
	return (free(doubled), subtracted);
}
