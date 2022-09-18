/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_shape_setter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:56:07 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/18 16:45:45 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int	set_shape_color(t_shape *shape, char **buf)
{
	double	args[3];
	int		status;
	t_color	*tmp;

	status = parse_float(args, buf, 3);
	if (status)
		return (ft_err("Error\n Invalid color\n"), status);
	status = check_color_range(args);
	if (status)
		return (ft_err("Error\n Invalid color range\n"), status);
	tmp = new_color(args[0], args[1], args[2]);
	free(shape->material->color);
	shape->material->color = color_normalize(tmp);
	free(tmp);
	return (status);
}

int	set_shape_orientation(t_shape *shape, char **buf)
{
	double		args[3];
	t_point		*tmp;
	int			status;

	status = parse_float(args, buf, 3);
	if (status)
		return (ft_err("Error\n Invalid orientation vector\n"), status);
	tmp = new_point(args[0], args[1], args[2]);
	shape->normalv = shape->get_normal(shape, tmp);
	free(tmp);
	return (status);
}
