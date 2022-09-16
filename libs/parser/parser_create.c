/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 22:11:30 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/16 20:26:22 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_rt_props	*new_rt_props(void)
{
	t_rt_props	*new;

	new = malloc(sizeof(t_rt_props));
	if (!new)
		return (NULL);
	new->id = P_SIZE;
	new->line = NULL;
	new->a = malloc(sizeof(t_ambient_props));
	new->a->ratio = 0;
	new->a->color = NULL;
	new->c = malloc(sizeof(t_camera_props));
	new->c->fov = 0;
	new->c->origin = NULL;
	new->c->direction = NULL;
	new->l = malloc(sizeof(t_light_props));
	new->s = malloc(sizeof(t_shape_props));
	new->s->shapes = NULL;
	new->status = 0;
	return (new);
}
