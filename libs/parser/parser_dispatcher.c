/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dispatcher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:48:17 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/09 20:54:45 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	parse_error(t_rt_props *props)
{
	(void)props;
	fprintf(stderr, "Error: Invalid file\n");
	return (-1);
}

static t_dispatcher	*get_parser(t_prop_id id)
{
	static t_dispatcher	*table[P_SIZE + 1];

	table[P_AMBIENT] = parse_ambient;
	table[P_CAMERA] = parse_camera;
	table[P_LIGHT] = parse_light;
	table[P_PLANE] = parse_plane;
	table[P_SPHERE] = parse_sphere;
	table[P_CYLINDER] = parse_cylinder;
	table[P_SIZE] = parse_error;
	return (table[id]);
}

t_rt_props	*new_rt_props(void)
{
	t_rt_props	*new;

	new = malloc(sizeof(t_rt_props));
	if (!new)
		return (NULL);
	new->id = P_SIZE;
	new->line = NULL;
	new->a = NULL;
	new->c = NULL;
	new->l = NULL;
	new->s = NULL;
	new->status = 0;
	return (new);
}

int	load(t_rt_props *p)
{
	int				status;
	t_dispatcher	*parse;

	p->id = get_prop_id(p->line);
	parse = get_parser(p->id);
	status = (*parse)(p);
	return (status);
}
