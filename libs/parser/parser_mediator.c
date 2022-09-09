/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_mediator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:08:18 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/09 15:48:57 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	handle_caps(const char *line)
{
	if (!ft_strncmp(line, "A ", 2))
		return (P_A);
	if (!ft_strncmp(line, "C ", 2))
		return (P_C);
	if (!ft_strncmp(line, "L ", 2))
		return (P_L);
	return (P_SIZE);
}

static int	handle_lower(const char *line)
{
	if (!ft_strncmp(line, "pl ", 3))
		return (P_pl);
	if (!ft_strncmp(line, "sp ", 3))
		return (P_sp);
	if (!ft_strncmp(line, "cy ", 3))
		return (P_cy);
	return (P_SIZE);
}

int	translate_startswith(const char *line)
{
	if (*line >= 'A' && *line <= 'Z')
		return (handle_caps(line));
	if (*line >= 'a' && *line <= 'z')
		return (handle_lower(line));
	fprintf(stderr, "Error: Invalid line start: %s\n", line);
	return (-1);
}
