/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:12:56 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/20 21:40:41 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	set_sphere_coords(t_shape *sphere, char **buf)
{
	double	args[3];
	int		status;

	status = parse_float(args, buf, 3);
	if (status)
		return (ft_err("Error\n Invalid coordinates\n"), status);
	sphere->sphere.center = (t_point){args[0], args[1], args[2], 1};
	return (status);
}

int	set_sphere_diameter(t_shape *sphere, char **buf)
{
	double	args[1];
	int		status;

	status = parse_float(args, buf, 1);
	if (status)
		return (ft_err("Error\n Invalid diameter\n"), status);
	sphere->sphere.radius = *args / 2;
	return (status);
}

static int	set_sphere_translation(t_shape *sphere)
{
	t_matrix	*tr;
	t_matrix	*scale;
	t_matrix	*product;

	tr = translation(sphere->sphere.center.x, sphere->sphere.center.y,
			sphere->sphere.center.z);
	if (!tr)
		return (free(tr), ft_err("Error: Invalid matrix translation\n"), 1);
	scale = scaling(sphere->sphere.radius, sphere->sphere.radius,
			sphere->sphere.radius);
	if (!scale)
		return (free(tr), free(scale),
			ft_err("Error: Invalid matrix scale\n"), 2);
	product = matrix_multiply(tr, scale);
	if (!product)
		return (free(tr), free(scale),
			ft_err("Error: Invalid matrix product\n"), 3);
	set_transform(sphere, product);
	free(tr);
	free(scale);
	return (0);
}

int	parse_sphere(t_rt_props *props)
{
	char		**args;
	char		**tmp;
	int			status;
	t_shape		*sphere;

	args = ft_split(props->line, ' ');
	if (count_args(args) != 4 || props->state != P_PROPS_OK)
		return (free_matrix(args), 1);
	tmp = ft_split(args[1], ',');
	sphere = new_sphere();
	status = set_material_props(sphere, props);
	status += set_sphere_coords(sphere, tmp);
	free_matrix(tmp);
	status = set_sphere_diameter(sphere, &args[2]);
	tmp = ft_split(args[3], ',');
	status += set_shape_color(sphere, tmp);
	free_matrix(tmp);
	set_sphere_translation(sphere);
	add_shape(props->s, sphere);
	free_matrix(args);
	return (status);
}
