/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:09:30 by itaureli          #+#    #+#             */
/*   Updated: 2022/08/21 14:14:44 by vwildner         ###   ########.fr       */
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
	t_shape			*s1;
	t_shape			*s2;
	t_matrix		*scale;

	new = new_world();
	if (!new)
	{
		fprintf(stderr, "Error: There was an error creating the world!");
		return (NULL);
	}
	add_light(new,
		new_point_light(new_point(-10, 10, -10), new_color(1, 1, 1)));
	s1 = new_sphere();
	free(s1->material->color);
	s1->material->color = new_color(0.8, 1.0, 0.6);
	s1->material->specular = 0.2;
	s1->material->diffuse = 0.7;
	s1->material->shininess = 200;
	add_sphere(new, s1);
	s2 = new_sphere();
	scale = scaling(0.5, 0.5, 0.5);
	set_transform(s2, scale);
	add_sphere(new, s2);
	return (new);
}
