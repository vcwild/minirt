/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:30:19 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/06 22:45:26 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_swap(void *a, void *b, size_t size)
{
	char	temp;
	char	*pa;
	char	*pb;

	*pa = (char *)a;
	*pb = (char *)b;
	while (size--)
	{
		temp = pa[size];
		pa[size] = pb[size];
		pb[size] = temp;
	}
}
