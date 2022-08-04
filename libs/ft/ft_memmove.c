/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:15:00 by vwildner          #+#    #+#             */
/*   Updated: 2021/05/29 18:15:01 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *) src;
	d = (char *) dest;
	if (s < d)
	{
		while (n--)
			d[n] = s[n];
		return (dest);
	}
	ft_memcpy(d, s, n);
	return (dest);
}
