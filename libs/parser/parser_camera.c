/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:12:20 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/15 20:15:49 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int	set_view_point(t_rt_props *props, char **buf)
{
	double	args[3];
	int		status;

	status = parse_float(args, buf, 3);
	if (status)
		return (fprintf(stderr, "Error: Invalid view point\n"), status);
	props->c->origin = new_point(args[0], args[1], args[2]);
	return (status);
}

int	set_direction(t_rt_props *props, char **buf)
{
	double	args[3];
	t_tuple	*tmp;
	int		status;

	status = parse_float(args, buf, 3);
	if (status)
		return (fprintf(stderr, "Error: Invalid camera direction\n"), 1);
	tmp = new_vector(args[0], args[1], args[2]);
	props->c->direction = normalize(tmp);
	free(tmp);
	return (status);
}

int	set_fov(t_rt_props *props, char **buf)
{
	double	args[1];
	int		status;

	status = parse_float(args, buf, 1);
	if (status)
		return (fprintf(stderr, "Error: Invalid camera fov\n"), 1);
	props->c->fov = *args;
	return (status);
}

int	parse_camera(t_rt_props *props)
{
	char	**args;
	char	**tmp;
	int		status;

	args = ft_split(props->line, ' ');
	if (count_args(args) != 4)
		return (fprintf(stderr, "Error: Invalid camera arguments\n"),
			free_matrix(args), 1);
	status = 0;
	tmp = ft_split(args[1], ',');
	status = set_view_point(props, tmp);
	free_matrix(tmp);
	tmp = ft_split(args[2], ',');
	status = set_direction(props, tmp);
	free_matrix(tmp);
	status = set_fov(props, &args[3]);
	free_matrix(args);
	return (status);
}