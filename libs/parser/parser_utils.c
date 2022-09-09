/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:55:13 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/09 15:48:02 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int	strip_extra_spaces(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	j = 0;
	tmp = (char *) malloc(ft_strlen(str) + 1);
	while (str[++i])
	{
		if (!ft_isspace(str[i]) || (i > 0 && !ft_isspace(str[i - 1])))
			tmp[j++] = str[i];
	}
	tmp[j] = '\0';
	ft_memcpy(str, tmp, j + 1);
	free(tmp);
	return (0);
}

int	borrow_line(char *line, char **acc, int index)
{
	acc[index] = ft_strdup(line);
	if (!acc[index])
		return (-1);
	free(line);
	return (0);
}
