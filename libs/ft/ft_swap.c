/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:30:19 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/07 17:37:52 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_swap(void *a, void *b, size_t size)
{
	char	*buf;

	buf = (char *) malloc(sizeof(char) * size);
	ft_memcpy(buf, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, buf, size);
	free(buf);
}
