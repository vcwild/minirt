/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:12:56 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/18 20:41:13 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	set_sphere_coords(t_shape *sphere, char **buf)
{
	double	args[3];
	int		status;

	status = parse_float(args, buf, 3);
	if (status)
		return (ft_err("Error: Invalid coordinates\n"), status);
	sphere->sphere.center = (t_point){args[0], args[1], args[2], 1};
	return (status);
}

int	set_sphere_diameter(t_shape *sphere, char **buf)
{
	double	args[1];
	int		status;

	status = parse_float(args, buf, 1);
	if (status)
		return (ft_err("Error: Invalid diameter\n"), status);
	sphere->sphere.radius = *args / 2;
	return (status);
}

int	parse_sphere(t_rt_props *props)
{
	char	**args;
	char	**tmp;
	int		status;
	t_shape	*sphere;

	args = ft_split(props->line, ' ');
	if (count_args(args) != 4)
		return (free_matrix(args), 1);
	tmp = ft_split(args[1], ',');
	sphere = new_sphere();
	sphere->material->ambient = props->a->ratio;
	sphere->material->diffuse = props->l->brightness;
	sphere->material->specular = props->l->brightness;
	status = set_sphere_coords(sphere, tmp);
	free_matrix(tmp);
	status = set_sphere_diameter(sphere, &args[2]);
	tmp = ft_split(args[3], ',');
	status = set_shape_color(sphere, tmp);
	free_matrix(tmp);
	add_shape(props->s, sphere);
	free_matrix(args);
	return (status);
}
