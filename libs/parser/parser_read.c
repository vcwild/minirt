/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:33:50 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/10 00:12:03 by vwildner         ###   ########.fr       */
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

	buf = (char *) malloc(PARSER_BUFFER_SIZE);
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
		return (fprintf(stderr, "Error: Could not open file\n"), NULL);
	acc = read_fd(fd);
	if (!acc)
		return (fprintf(stderr, "Error: Invalid read size\n"), free(acc), NULL);
	strip_extra_spaces(acc);
	final = ft_split(acc, '\n');
	free(acc);
	return (final);
}
