/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shape_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:32:29 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/19 20:26:20 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

double	rand_double(void)
{
	return ((double)rand() / RAND_MAX);
}

double	get_discriminant(t_sphere *s, t_ray *r, t_disc_coef *coef)
{
	t_tuple	*target;

	target = subtract_tuples(r->origin, &s->center);
	coef->a = dot(r->direction, r->direction);
	coef->b = 2 * dot(r->direction, target);
	coef->c = dot(target, target) - 1;
	free(target);
	return (coef->b * coef->b - 4 * coef->a * coef->c);
}
