/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:30:19 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/07 11:41:22 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_swap(void *a, void *b, size_t size)
{
	char	temp;
	char	*pa;
	char	*pb;

	pa = malloc(size);
	pb = malloc(size);
	if (pa == NULL || pb == NULL)
		return ;
	*pa = *(char *)a;
	*pb = *(char *)b;
	while (size--)
	{
		temp = pa[size];
		pa[size] = pb[size];
		pb[size] = temp;
	}
}
