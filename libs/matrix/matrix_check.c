/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:25:23 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/09 21:21:36 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

int	matrix_equals(t_matrix *a, t_matrix *b)
{
	int	i;
	int	j;

	if (a->size != b->size)
		return (0);
	i = -1;
	while (++i < a->size)
	{
		j = -1;
		while (++j < a->size)
		{
			if (a->data[i][j] != b->data[i][j])
				return (0);
		}
	}
	return (1);
}
