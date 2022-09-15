/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 22:11:47 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/15 19:41:00 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void	destroy_ambient_props(t_ambient_props *a)
{
	if (a->color)
		free(a->color);
	free(a);
}

static void	destroy_camera_props(t_camera_props *c)
{
	if (c->origin)
		free(c->origin);
	if (c->direction)
		free(c->direction);
	free(c);
}

static void	destroy_light_props(t_light_props *l)
{
	if (l->pl)
		destroy_point_light(l->pl);
	if (l->color)
		free(l->color);
	free(l);
}

void	destroy_rt_props(t_rt_props *props)
{
	destroy_ambient_props(props->a);
	destroy_camera_props(props->c);
	destroy_light_props(props->l);
	if (props->s)
		free(props->s);
	free(props);
}
