/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dispatcher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:48:17 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/21 23:28:20 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	parse_error(t_rt_props *props)
{
	(void)props;
	ft_err("Error\n Invalid file\n");
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

static int	load(t_rt_props *p)
{
	int				status;
	t_dispatcher	*parse;

	p->id = get_prop_id(p->line);
	parse = get_parser(p->id);
	status = (*parse)(p);
	return (status);
}

int	load_scene(const char *file, t_rt_props *props)
{
	int		i;
	int		status;
	char	**lines;

	i = -1;
	lines = readlines(file);
	if (!lines)
		return (ft_err("Error\n Could not read file\n"),
			free_matrix(lines), -1);
	if (count_args(lines) < 3)
		return (ft_err("Error\n Invalid file\n"),
			free_matrix(lines), -1);
	status = 0;
	while (lines[++i])
	{
		props->line = lines[i];
		status = load(props);
		if (status)
		{
			ft_err("Error\n Invalid scene file\n");
			break ;
		}
	}
	free_matrix(lines);
	return (status);
}
