/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 22:11:30 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/18 18:39:36 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static t_ambient_props	*new_ambient_props(void)
{
	t_ambient_props	*new;

	new = malloc(sizeof(t_ambient_props));
	if (!new)
		return (NULL);
	new->ratio = 0;
	new->color = NULL;
	return (new);
}

static t_camera_props	*new_camera_props(void)
{
	t_camera_props	*new;

	new = malloc(sizeof(t_camera_props));
	if (!new)
		return (NULL);
	new->fov = 0;
	new->origin = NULL;
	new->direction = NULL;
	return (new);
}

static t_light_props	*new_light_props(void)
{
	t_light_props	*new;

	new = malloc(sizeof(t_light_props));
	if (!new)
		return (NULL);
	new->pl = NULL;
	new->color = NULL;
	new->brightness = 0;
	return (new);
}

t_shape_props	*new_shape_props(void)
{
	t_shape_props	*new;

	new = malloc(sizeof(t_shape_props));
	if (!new)
		return (NULL);
	new->objects.spheres = NULL;
	new->objects.sphere_count = 0;
	new->objects.total = 0;
	return (new);
}

t_rt_props	*new_rt_props(void)
{
	t_rt_props	*new;

	new = malloc(sizeof(t_rt_props));
	if (!new)
		return (NULL);
	new->id = P_SIZE;
	new->line = NULL;
	new->a = new_ambient_props();
	if (!new->a)
		return (ft_err("Error\n malloc failed for ambient props"), new);
	new->c = new_camera_props();
	if (!new->c)
		return (ft_err("Error\n malloc failed for camera props"), new);
	new->l = new_light_props();
	if (!new->l)
		return (ft_err("Error\n malloc failed for light props"), new);
	new->s = new_shape_props();
	if (!new->s)
		return (ft_err("Error\n malloc failed for shape props"), new);
	new->status = 0;
	return (new);
}
