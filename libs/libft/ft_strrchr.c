/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:16:35 by vwildner          #+#    #+#             */
/*   Updated: 2021/05/29 18:16:37 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s_end;

	if (c > 127)
		c %= 256;
	s_end = s;
	while (*s_end)
		s_end++;
	while (s_end != s)
	{
		if (*s_end == c)
			return ((char *)s_end);
		s_end--;
	}
	if (*s_end == c)
		return ((char *)s_end);
	return (NULL);
}
