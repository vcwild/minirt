/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:12:36 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/16 22:12:54 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	check_light_props(t_rt_props *props)
{
	if (props->l->pl == NULL
		&& props->l->brightness == 0
		&& props->l->color == NULL)
		return (0);
	return (1);
}

static int	set_point_light(t_rt_props *props, char **buf)
{
	double	args[3];
	t_point	*p;
	t_color	*c;
	int		status;

	status = parse_float(args, buf, 3);
	if (status)
		return (ft_err("Error: Invalid light point\n"), status);
	p = new_point(args[0], args[1], args[2]);
	c = new_color(props->a->color->r, props->a->color->g, props->a->color->b);
	props->l->pl = new_point_light(p, c);
	return (status);
}

static int	set_brightness(t_rt_props *props, char **buf)
{
	double	args[1];
	int		status;

	status = parse_float(args, buf, 1);
	if (status)
		return (ft_err("Error: Invalid light brightness\n"), 1);
	props->l->brightness = *args;
	return (status);
}

static int	set_color(t_rt_props *props, char **buf)
{
	double	args[3];
	int		status;
	t_color	*tmp;

	status = parse_float(args, buf, 3);
	if (status)
		return (ft_err("Error: Invalid light color\n"), 1);
	tmp = new_color(args[0], args[1], args[2]);
	props->l->color = color_normalize(tmp);
	free(tmp);
	return (status);
}

int	parse_light(t_rt_props *props)
{
	char	**args;
	char	**tmp;

	if (check_light_props(props))
		return (ft_err("Error: Light already defined\n"), 1);
	args = ft_split(props->line, ' ');
	if (count_args(args) != 4)
		return (free_matrix(args), 2);
	tmp = ft_split(args[1], ',');
	if (set_point_light(props, tmp))
		return (free_matrix(tmp), free_matrix(args), 3);
	free_matrix(tmp);
	if (set_brightness(props, &args[2]))
		return (free_matrix(args), 4);
	tmp = ft_split(args[3], ',');
	if (set_color(props, tmp))
		return (free_matrix(tmp), free_matrix(args), 5);
	return (free_matrix(tmp), free_matrix(args), 0);
}
