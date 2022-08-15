/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shape_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:32:29 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/14 20:50:09 by vwildner         ###   ########.fr       */
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
	t_point	*center;

	(void)s;
	center = new_point(0, 0, 0);
	target = subtract_tuples(r->origin, center);
	coef->a = dot(r->direction, r->direction);
	coef->b = 2 * dot(r->direction, target);
	coef->c = dot(target, target) - 1;
	free(center);
	free(target);
	return (coef->b * coef->b - 4 * coef->a * coef->c);
}
