/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:13:27 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/20 21:39:46 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	set_cylinder_coords(t_shape *cyl, char **buf)
{
	double	args[3];
	int		status;

	status = parse_float(args, buf, 3);
	if (status)
		return (ft_err("Error\n Invalid coordinates\n"), status);
	cyl->cylinder.position = (t_point){args[0], args[1], args[2], 1};
	return (status);
}

static int	set_cylinder_diameter(t_shape *cyl, char **buf)
{
	double	args[1];
	int		status;

	status = parse_float(args, buf, 1);
	if (status)
		return (ft_err("Error\n Invalid diameter\n"), status);
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
		return (ft_err("Error\n Invalid height\n"), status);
	half_height = *args / 2;
	cyl->cylinder.min = -half_height;
	cyl->cylinder.max = half_height;
	cyl->cylinder.closed = true;
	return (status);
}

static int	set_cylinder_translation(t_shape *cyl)
{
	t_matrix	*tr;
	t_matrix	*rot;
	t_matrix	*scale;
	t_matrix	*product;

	tr = translation(cyl->cylinder.position.x, cyl->cylinder.position.y,
			cyl->cylinder.position.z);
	rot = get_rotation_matrix(cyl->normalv);
	scale = scaling(cyl->cylinder.radius, 1, cyl->cylinder.radius);
	product = matrix_multiply_3(tr, rot, scale);
	if (!product)
		return (free(tr), free(rot), free(scale), free(product),
			ft_err("Error: Invalid matrix product\n"), 4);
	set_transform(cyl, product);
	free(tr);
	free(rot);
	free(scale);
	return (0);
}

int	parse_cylinder(t_rt_props *props)
{
	char	**args;
	char	**tmp;
	int		status;
	t_shape	*cylinder;

	args = ft_split(props->line, ' ');
	if (count_args(args) != 6 || props->state != P_PROPS_OK)
		return (free_matrix(args), 1);
	tmp = ft_split(args[1], ',');
	cylinder = new_cylinder();
	set_material_props(cylinder, props);
	status = set_cylinder_coords(cylinder, tmp);
	free_matrix(tmp);
	tmp = ft_split(args[2], ',');
	status += set_shape_orientation(cylinder, tmp);
	free_matrix(tmp);
	status += set_cylinder_diameter(cylinder, &args[3]);
	status += set_cylinder_height(cylinder, &args[4]);
	tmp = ft_split(args[5], ',');
	status += set_shape_color(cylinder, tmp);
	set_cylinder_translation(cylinder);
	free_matrix(tmp);
	add_shape(props->s, cylinder);
	free_matrix(args);
	return (status);
}
