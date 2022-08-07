/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:37:52 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/07 18:38:48 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <canvas.h>

static int	handle_write(int fd, t_ppm *ppm, int line_length)
{
	int	i;

	write(fd, ppm->header, ft_strlen(ppm->header));
	while (ppm->data)
	{
		i = 0;
		while (i <= (line_length - 3))
		{
			write(fd, ppm->data++, sizeof(u_int));
			i += 3;
		}
		write(fd, "\n", 1);
	}
}

int	write_ppm(t_canvas *c, char *filename)
{
	int		fd;
	t_ppm	*ppm;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!fd)
	{
		fprintf(stderr, "Error: Could not open file `%s`\n", filename);
		return (1);
	}
	ppm = canvas_to_ppm(c);
	handle_write(fd, ppm, CANVAS_PPM_MAX_LINE_LENGTH);
	free(ppm->header);
	free(ppm->data);
	free(ppm);
	return (0);
}
