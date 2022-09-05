/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:35:40 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/04 10:25:17 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <world.h>

void	destroy_world(t_world *w)
{
	ft_lstclear(&w->lights, (void (*)(void *))destroy_point_light);
	ft_lstclear(&w->objects.spheres, (void (*)(void *))destroy_sphere);
	free(w);
}

void	destroy_computations(t_computations *c)
{
	free(c->eyev);
	free(c->normalv);
	free(c->point);
	free(c->over_point);
	free(c);
}
