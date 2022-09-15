/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:12:36 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/15 19:48:41 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int	set_point_light(t_rt_props *props, char **buf)
{
	double	args[3];
	t_point	*p;
	t_color	*c;
	int		status;

	status = parse_float(args, buf, 3);
	if (status)
		return (fprintf(stderr, "Error: Invalid light point\n"), status);
	p = new_point(args[0], args[1], args[2]);
	c = new_color(props->a->color->r, props->a->color->g, props->a->color->b);
	props->l->pl = new_point_light(p, c);
	return (status);
}

int	set_brightness(t_rt_props *props, char **buf)
{
	double	args[1];
	int		status;

	status = parse_float(args, buf, 1);
	if (status)
		return (fprintf(stderr, "Error: Invalid light brightness\n"), 1);
	props->l->brightness = *args;
	return (status);
}

int	set_color(t_rt_props *props, char **buf)
{
	double	args[3];
	int		status;
	t_color	*tmp;
	t_color	*normalized;

	status = parse_float(args, buf, 3);
	if (status)
		return (fprintf(stderr, "Error: Invalid light color\n"), 1);
	tmp = new_color(args[0], args[1], args[2]);
	normalized = color_normalize(tmp);
	props->l->color = new_color(normalized->r, normalized->g, normalized->b);
	free(tmp);
	free(normalized);
	return (status);
}

int	parse_light(t_rt_props *props)
{
	char	**args;
	char	**tmp;
	int		status;

	args = ft_split(props->line, ' ');
	if (count_args(args) != 4)
		return (fprintf(stderr, "Error: Invalid light arguments\n"),
			free_matrix(args), 1);
	status = 0;
	tmp = ft_split(args[1], ',');
	status = set_point_light(props, tmp);
	free_matrix(tmp);
	status = set_brightness(props, &args[2]);
	tmp = ft_split(args[3], ',');
	status = set_color(props, tmp);
	free_matrix(tmp);
	free_matrix(args);
	return (status);
}
