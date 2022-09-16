/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:55:13 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/16 14:04:11 by vwildner         ###   ########.fr       */
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

size_t	count_args(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	parse_float(double *dest, char **origin, size_t nargs)
{
	size_t	i;

	if (count_args(origin) < nargs)
		return (1);
	i = 0;
	while (i < nargs)
	{
		if (!ft_isfloat(origin[i]))
			return (1);
		dest[i] = ft_atof(origin[i]);
		i++;
	}
	return (0);
}

void	print_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		printf("%s\n", args[i]);
		i++;
	}
}
