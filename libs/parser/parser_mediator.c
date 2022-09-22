/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_mediator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:08:18 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/18 20:22:13 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	handle_caps(const char *line)
{
	if (!ft_strncmp(line, "A ", 2))
		return (P_AMBIENT);
	if (!ft_strncmp(line, "C ", 2))
		return (P_CAMERA);
	if (!ft_strncmp(line, "L ", 2))
		return (P_LIGHT);
	return (P_SIZE);
}

static int	handle_lower(const char *line)
{
	if (!ft_strncmp(line, "pl ", 3))
		return (P_PLANE);
	if (!ft_strncmp(line, "sp ", 3))
		return (P_SPHERE);
	if (!ft_strncmp(line, "cy ", 3))
		return (P_CYLINDER);
	return (P_SIZE);
}

t_prop_id	get_prop_id(const char *line)
{
	if (*line >= 'A' && *line <= 'Z')
		return (handle_caps(line));
	if (*line >= 'a' && *line <= 'z')
		return (handle_lower(line));
	ft_err("Error\n Invalid line start ");
	ft_err(line);
	ft_err("\n");
	return (P_SIZE);
}
