/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:33:50 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/18 16:45:45 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void	concat_line(char **buf, char **acc)
{
	char	*tmp;

	tmp = ft_strjoin(*acc, *buf);
	free(*acc);
	*acc = ft_strdup(tmp);
	free(tmp);
}

char	*read_fd(int fd)
{
	ssize_t	size;
	char	*buf;
	char	*acc;

	buf = (char *) malloc(PARSER_BUFFER_SIZE + 1);
	acc = ft_calloc(1, 1);
	size = read(fd, buf, PARSER_BUFFER_SIZE);
	while (size)
	{
		buf[size] = '\0';
		concat_line(&buf, &acc);
		size = read(fd, buf, PARSER_BUFFER_SIZE);
	}
	free(buf);
	if (size == -1)
		return (NULL);
	return (acc);
}

char	**readlines(const char *file)
{
	char	**final;
	char	*acc;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_err("Error\n Could not open file\n"), NULL);
	acc = read_fd(fd);
	if (!acc)
		return (ft_err("Error\n Invalid read size\n"), free(acc), NULL);
	strip_extra_spaces(acc);
	final = ft_split(acc, '\n');
	free(acc);
	return (final);
}
