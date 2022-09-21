/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:13:14 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/20 21:40:27 by vwildner         ###   ########.fr       */
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

static int	set_plane_translation(t_shape *plane)
{
	t_matrix	*tr;
	t_matrix	*rot;
	t_matrix	*product;

	tr = translation(plane->plane.position.x, plane->plane.position.y,
			plane->plane.position.z);
	if (!tr)
		return (free(tr), ft_err("Error: Invalid matrix translation\n"), 1);
	rot = get_rotation_matrix(plane->normalv);
	if (!rot)
		return (free(tr), free(rot),
			ft_err("Error: Invalid orientation vector\n"), 2);
	product = matrix_multiply(tr, rot);
	if (!product)
		return (free(tr), free(rot),
			ft_err("Error: Invalid matrix product\n"), 3);
	set_transform(plane, product);
	free(tr);
	free(rot);
	return (0);
}

int	parse_plane(t_rt_props *props)
{
	char	**args;
	char	**tmp;
	int		status;
	t_shape	*plane;

	args = ft_split(props->line, ' ');
	if (count_args(args) != 4 || props->state != P_PROPS_OK)
		return (free_matrix(args), 1);
	tmp = ft_split(args[1], ',');
	plane = new_plane();
	status = set_material_props(plane, props);
	status += set_plane_coords(plane, tmp);
	free_matrix(tmp);
	tmp = ft_split(args[2], ',');
	status += set_shape_orientation(plane, tmp);
	free_matrix(tmp);
	tmp = ft_split(args[3], ',');
	status += set_shape_color(plane, tmp);
	status += set_plane_translation(plane);
	free_matrix(tmp);
	add_shape(props->s, plane);
	free_matrix(args);
	return (status);
}
