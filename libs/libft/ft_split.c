/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:15:25 by vwildner          #+#    #+#             */
/*   Updated: 2021/05/29 18:15:39 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	size_t	len;
	size_t	is_c;

	len = 0;
	is_c = 1;
	while (*s)
	{
		if (*s != c && is_c)
		{
			is_c = 0;
			len++;
		}
		else if (*s++ == c)
			is_c = 1;
	}
	return (len);
}

static char const	*skip_c_in_s(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

static char	**ft_word_split(char **s_list, char const *s, char c, size_t len)
{
	char	*c_pos;
	int		idx;
	char	**s_list_start;

	s_list_start = s_list;
	idx = 0;
	s = skip_c_in_s(s, c);
	while (len--)
	{
		c_pos = ft_strchr(s, c);
		if (c_pos != NULL)
		{
			*s_list = ft_substr(s, idx, c_pos - s);
			s = skip_c_in_s(c_pos, c);
		}
		else
			*s_list = ft_substr(s, idx, ft_strlen(s) + 1);
		s_list++;
	}
	*s_list = NULL;
	return (s_list_start);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**s_list;

	if (s == NULL)
		return (NULL);
	size = word_count(s, c);
	s_list = malloc(sizeof(char **) * (size + 1));
	if (s_list == NULL)
		return (NULL);
	return (ft_word_split(s_list, s, c, size));
}
