/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_mediator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:08:18 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/16 17:25:03 by vwildner         ###   ########.fr       */
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
	ft_putstr_fd("Error: Invalid line start ", STDERR_FILENO);
	ft_putstr_fd(line, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (-1);
}
