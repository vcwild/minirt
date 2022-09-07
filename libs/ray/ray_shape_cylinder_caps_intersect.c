/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shape_cylinder_caps_intersect.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:44:56 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/06 21:17:10 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

bool	check_cap(t_ray *r, double t)
{
	double	x;
	double	z;

	x = r->origin->x + t * r->direction->x;
	z = r->origin->z + t * r->direction->z;
	return (pow(x, 2) + pow(z, 2) <= 1);
}

void	intersect_caps(t_shape *s, t_ray *r, t_intersections *xs)
{
	double			t;
	t_intersection	*x;

	if (!s->cylinder.closed || dequals(r->direction->y, 0))
		return ;
	t = (s->cylinder.min - r->origin->y) / r->direction->y;
	if (check_cap(r, t))
	{
		x = new_intersection(t, s, OBJ_CYLINDER);
		add_intersection(xs, x);
	}
	t = (s->cylinder.max - r->origin->y) / r->direction->y;
	if (check_cap(r, t))
	{
		x = new_intersection(t, s, OBJ_CYLINDER);
		add_intersection(xs, x);
	}
}
