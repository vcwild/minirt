/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:11:28 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/18 16:45:45 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	check_ambient_props(t_rt_props *props)
{
	if (props->a->ratio == 0 && props->a->color == NULL)
		return (0);
	return (1);
}

t_color	*get_normalized_color(char **buf)
{
	int		status;
	double	args[3];
	t_color	*final;
	t_color	*tmp;

	status = parse_float(args, buf, 3);
	if (status)
		return (ft_err("Error\n Invalid color params\n"), NULL);
	status = check_color_range(args);
	if (status)
		return (ft_err("Error\n Invalid color range\n"), NULL);
	tmp = new_color(args[0], args[1], args[2]);
	final = color_normalize(tmp);
	free(tmp);
	return (final);
}

static int	set_ambient_ratio(t_rt_props *props, char **buf)
{
	double	args[1];
	int		status;

	status = parse_float(args, buf, 1);
	if (status)
		return (ft_err("Error\n Invalid ratio\n"), status);
	if (*args > 1 || *args < 0)
		return (ft_err("Error: Invalid ratio range\n"), 1);
	props->a->ratio = *args;
	return (status);
}

static int	set_ambient_color(t_rt_props *props, char **buf)
{
	t_color	*color;

	color = get_normalized_color(buf);
	if (!color)
		return (1);
	props->a->color = color;
	return (0);
}

int	parse_ambient(t_rt_props *props)
{
	char		**args;
	char		**tmp;

	if (check_ambient_props(props))
		return (ft_err("Error\n Ambient was already set\n"), 1);
	args = ft_split(props->line, ' ');
	if (count_args(args) != 3)
		return (free_matrix(args), 2);
	if (set_ambient_ratio(props, &args[1]))
		return (free_matrix(args), 3);
	tmp = ft_split(args[2], ',');
	free_matrix(args);
	if (set_ambient_color(props, tmp))
		return (free_matrix(tmp), 4);
	free_matrix(tmp);
	props->state |= P_AMBIENT;
	return (0);
}
