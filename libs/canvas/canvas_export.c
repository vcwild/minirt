/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:37:52 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/07 15:44:31 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <canvas.h>

static void	export_element(char *buf, void *el)
{
	size_t	size;

	size = ft_strlen(buf);
	size += ft_strlen(el) + 2;
	buf = ft_realloc(buf, size);
	ft_strlcat(buf, (char *)(el), size - 1);
	ft_strlcat(buf, " ", size);
}

static void	export_int(char *buf, int el)
{
	size_t	size;

	size = ft_strlen(buf) + 2;
	buf = ft_realloc(buf, size);
	ft_strlcat(buf, ft_itoa(el), size - 1);
	ft_strlcat(buf, " ", size);
}

static void	export_pixel(char *buf, t_color *color)
{
	export_int(buf, to_rgb(color->r));
	export_int(buf, to_rgb(color->g));
	export_int(buf, to_rgb(color->b));
}

static t_ppm	*canvas_to_ppm(t_canvas *c)
{
	t_ppm	*ppm;

	ppm = (t_ppm *) malloc(sizeof(t_ppm));
	ppm->header = ft_strdup("P3\n");
	ppm->data = ft_strdup("");
	export_int(ppm->header, (int) c->width);
	export_int(ppm->header, (int) c->height);
	export_element(ppm->header, "\n255\n");
	while (c->height--)
	{
		while (c->width--)
		{
			export_pixel(ppm->data, c->pixels[c->height][c->width]);
		}
		export_element(ppm->data, "\n");
	}
	return (ppm);
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
	write(fd, ppm->header, ft_strlen(ppm->header));
	write(fd, ppm->data, ft_strlen(ppm->data));
	free(ppm->header);
	free(ppm->data);
	free(ppm);
	return (0);
}
