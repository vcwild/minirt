/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:13:14 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/16 17:38:45 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	set_plane_coords(t_shape *shape, char **buf)
{
	double	args[3];
	int		status;

	status = parse_float(args, buf, 3);
	if (status)
		return (ft_err("Error: Invalid coordinates\n"), status);
	shape->plane.position = (t_point){args[0], args[1], args[2], 1};
	return (status);
}

int	parse_plane(t_rt_props *props)
{
	char	**args;
	char	**tmp;
	int		status;
	t_shape	*plane;
	t_list	*new;

	args = ft_split(props->line, ' ');
	tmp = ft_split(args[1], ',');
	plane = new_plane();
	status = set_plane_coords(plane, tmp);
	free_matrix(tmp);
	tmp = ft_split(args[2], ',');
	status = set_shape_orientation(plane, tmp);
	free_matrix(tmp);
	tmp = ft_split(args[3], ',');
	status = set_shape_color(plane, tmp);
	free_matrix(tmp);
	new = ft_lstnew(plane);
	ft_lstadd_back(&props->s->shapes, new);
	free_matrix(args);
	return (status);
}
