/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:17:39 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/14 20:45:27 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

t_intersection	*new_intersection( double t, t_shape *obj, t_object_type type)
{
	t_intersection	*x;

	x = (t_intersection *)malloc(sizeof(t_intersection));
	if (!x)
		return (fprintf(stderr, "Error: new_intersection failed\n"), NULL);
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

static void	handle_intersections_size(t_intersections *xs)
{
	t_intersection	**x;

	if (xs->count >= xs->size)
	{
		x = malloc(sizeof(t_intersection *) * (xs->size + RAY_XS_SIZE));
		ft_memmove(x, xs->intersections, sizeof(t_intersection *)
			* (xs->size));
		free(xs->intersections);
		xs->intersections = x;
		xs->size += RAY_XS_SIZE;
	}
}

void	add_intersection(t_intersections *xs, t_intersection *new)
{
	handle_intersections_size(xs);
	xs->intersections[xs->count] = new;
	xs->count++;
	xs->is_sorted = 0;
}

void	sort_intersections(t_intersections *xs)
{
	size_t			i;
	size_t			j;
	t_intersection	*tmp;

	if (xs->is_sorted)
		return ;
	i = -1;
	while (++i < xs->count)
	{
		j = i;
		while (++j < xs->count)
		{
			if (xs->intersections[i]->t > xs->intersections[j]->t)
			{
				tmp = xs->intersections[i];
				xs->intersections[i] = xs->intersections[j];
				xs->intersections[j] = tmp;
			}
		}
	}
	xs->is_sorted = 1;
}
