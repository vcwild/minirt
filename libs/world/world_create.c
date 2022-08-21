/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:09:30 by itaureli          #+#    #+#             */
/*   Updated: 2022/08/21 13:00:00 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <world.h>

t_objects	*new_objects(void)
{
	t_objects	*new;

	new = (t_objects *)malloc(sizeof(t_objects));
	if (!new)
		return (free(new), NULL);
	return (new);
}

t_world	*new_world(void)
{
	t_world	*new;

	new = (t_world *)malloc(sizeof(t_world));
	if (!new)
		return (free(new), NULL);
	new->lights = NULL;
	new->objects.spheres = NULL;
	new->objects.sphere_count = 0;
	new->objects.total = 0;
	return (new);
}

int	add_light(t_world *w, t_point_light *pl)
{
	t_list	*new;

	new = ft_lstnew(pl);
	if (!new)
	{
		fprintf(stderr, "Error: There was an error adding a light source!");
		return (1);
	}
	ft_lstadd_back(&w->lights, new);
	return (0);
}

int	add_sphere(t_world *w, t_shape *sphere)
{
	t_list	*new;

	new = ft_lstnew(sphere);
	if (!new)
	{
		fprintf(stderr, "Error: There was an error adding a sphere!");
		return (1);
	}
	ft_lstadd_back(&w->objects.spheres, new);
	w->objects.sphere_count += 1;
	w->objects.total += 1;
	return (0);
}

t_world	*default_world(void)
{
	t_world			*new;
	t_point_light	*pl;
	t_shape			*sphere;

	new = new_world();
	pl = new_point_light(new_point(-10, 10, -10), new_color(1, 1, 1));
	add_light(new, pl);
	sphere = new_sphere();
	free(sphere->material->color);
	sphere->material->color = new_color(0.8, 1.0, 0.6);
	sphere->material->diffuse = 0.7;
	sphere->material->specular = 0.2;
	add_sphere(new, sphere);
	destroy_sphere(sphere);
	sphere = new_sphere();
	free(sphere->transform);
	sphere->transform = scaling(0.5, 0.5, 0.5);
	add_sphere(new, sphere);
	return (new);
}
