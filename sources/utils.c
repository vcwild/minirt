/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 09:45:04 by itaureli          #+#    #+#             */
/*   Updated: 2022/09/18 09:58:19 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	print_error(char *message)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	return (1);
}

int	is_valid_extension(char *render_file)
{
	char	*ext;

	if (!render_file)
		return (0);
	ext = ft_strrchr(render_file, '.');
	if (!ext)
	{
		print_error("File without especific extension");
		return (0);
	}
	else if (!(ft_strncmp(ext, ".rt", 4) == 0))
	{
		print_error("Invalid file extension");
		return (0);
	}
	return (1);
}
