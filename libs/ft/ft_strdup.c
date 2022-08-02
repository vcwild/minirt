/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:15:48 by vwildner          #+#    #+#             */
/*   Updated: 2021/05/30 20:24:04 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*cpy;
	size_t		size;

	size = ft_strlen(s1) + 1;
	cpy = (char *)malloc(size);
	if (cpy == NULL)
		return (NULL);
	ft_strlcpy(cpy, s1, size);
	return (cpy);
}
