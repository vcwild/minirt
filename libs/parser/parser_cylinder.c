/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:13:27 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/16 17:48:14 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	set_cylinder_coords(t_shape *cyl, char **buf)
{
	double	args[3];
	int		status;

	status = parse_float(args, buf, 3);
	if (status)
		return (ft_err("Error: Invalid coordinates\n"), status);
	cyl->cylinder.position = (t_point){args[0], args[1], args[2], 1};
	return (status);
}

static int	set_cylinder_diameter(t_shape *cyl, char **buf)
{
	double	args[1];
	int		status;

	status = parse_float(args, buf, 1);
	if (status)
		return (ft_err("Error: Invalid diameter\n"), status);
	cyl->cylinder.radius = args[0] / 2;
	return (status);
}

static int	set_cylinder_height(t_shape *cyl, char **buf)
{
	double	args[1];
	double	half_height;
	int		status;

	status = parse_float(args, buf, 1);
	if (status)
		return (ft_err("Error: Invalid height\n"), status);
	half_height = *args / 2;
	cyl->cylinder.min = -half_height;
	cyl->cylinder.max = half_height;
	cyl->cylinder.closed = true;
	return (status);
}

int	parse_cylinder(t_rt_props *props)
{
	char	**args;
	char	**tmp;
	int		status;
	t_list	*new;
	t_shape	*cylinder;

	args = ft_split(props->line, ' ');
	if (count_args(args) != 6)
		return (free_matrix(args), 1);
	tmp = ft_split(args[1], ',');
	cylinder = new_cylinder();
	status = set_cylinder_coords(cylinder, tmp);
	free_matrix(tmp);
	tmp = ft_split(args[2], ',');
	status = set_shape_orientation(cylinder, tmp);
	free_matrix(tmp);
	status = set_cylinder_diameter(cylinder, &args[3]);
	status = set_cylinder_height(cylinder, &args[4]);
	tmp = ft_split(args[5], ',');
	status = set_shape_color(cylinder, tmp);
	free_matrix(tmp);
	new = ft_lstnew(cylinder);
	ft_lstadd_back(&props->s->shapes, new);
	free_matrix(args);
	return (status);
}
