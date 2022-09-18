/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:12:56 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/18 16:45:45 by itaureli         ###   ########.fr       */
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

int	parse_sphere(t_rt_props *props)
{
	char	**args;
	char	**tmp;
	int		status;
	t_list	*new;
	t_shape	*sphere;

	args = ft_split(props->line, ' ');
	if (count_args(args) != 4)
		return (free_matrix(args), 1);
	tmp = ft_split(args[1], ',');
	sphere = new_sphere();
	status = set_sphere_coords(sphere, tmp);
	free_matrix(tmp);
	status = set_sphere_diameter(sphere, &args[2]);
	tmp = ft_split(args[3], ',');
	status = set_shape_color(sphere, tmp);
	free_matrix(tmp);
	new = ft_lstnew(sphere);
	ft_lstadd_back(&props->s->shapes, new);
	free_matrix(args);
	return (status);
}
