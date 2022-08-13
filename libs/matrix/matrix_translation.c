/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:28:55 by itaureli          #+#    #+#             */
/*   Updated: 2022/08/13 10:43:22 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_matrix	*translation(double x, double y, double z)
{
	t_matrix	*new;
	int			i;
	int			j;

	new = new_matrix(4, NULL);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i == 3 && j == 3)
				new->data[i][j] = 1;
			else if (i == j)
				new->data[i][j] = 1;
			else
				new->data[i][j] = 0;
		}
	}
	new->data[0][3] = x;
	new->data[1][3] = y;
	new->data[2][3] = z;
	return (new);
}
