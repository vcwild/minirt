/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:17:39 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/18 16:51:24 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

t_intersection	*new_intersection( double t, t_shape *obj, t_object_type type)
{
	t_intersection	*x;

	x = (t_intersection *)malloc(sizeof(t_intersection));
	if (!x)
		return (ft_err("Error\n new_intersection malloc failed\\n"), NULL);
	x->t = t;
	x->shape = obj;
	x->object_type = type;
	return (x);
}

t_intersections	*new_intersections_list(void)
{
	t_intersections	*intersections;

	intersections = malloc(sizeof(t_intersections));
	intersections->count = 0;
	intersections->size = RAY_XS_SIZE;
	intersections->is_sorted = 0;
	intersections->intersections = malloc(sizeof(t_intersection *)
			* RAY_XS_SIZE);
	return (intersections);
}
