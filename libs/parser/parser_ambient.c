/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:11:28 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/16 17:43:56 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	set_ratio(t_rt_props *props, char **buf)
{
	if (count_args(buf) != 3)
		return (1);
	props->a->ratio = ft_atof(buf[1]);
	return (0);
}

static int	set_color(t_rt_props *props, char **buf)
{
	int		i;
	int		rgb[3];
	t_color	*tmp;

	i = -1;
	while (++i < 3)
	{
		rgb[i] = ft_atoi(buf[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (1);
	}
	tmp = new_color(rgb[0], rgb[1], rgb[2]);
	props->a->color = color_normalize(tmp);
	free(tmp);
	return (0);
}

int	parse_ambient(t_rt_props *props)
{
	char		**args;
	char		**tmp;
	int			status;

	status = 0;
	args = ft_split(props->line, ' ');
	status = set_ratio(props, args);
	if (status)
		return (free_matrix(args), 1);
	tmp = ft_split(args[2], ',');
	free_matrix(args);
	status = set_color(props, tmp);
	free_matrix(tmp);
	return (status);
}
