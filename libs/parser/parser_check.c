/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:10:18 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/16 18:10:32 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int	check_color_range(double *args)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (args[i] < 0 || args[i] > 255)
			return (1);
	}
	return (0);
}
