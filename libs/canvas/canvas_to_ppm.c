/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_to_ppm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:38:33 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/10 19:23:30 by vwildner         ###   ########.fr       */
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

t_ppm	*canvas_to_ppm(t_canvas *c)
{
	t_ppm	*ppm;
	int		i;

	i = 0;
	ppm = (t_ppm *) malloc(sizeof(t_ppm));
	ppm->header = ft_strdup("P3\n");
	ppm->data = (u_int *) malloc(sizeof(u_int) * c->height * c->width * 3 + 1);
	export_element(ppm->header, ft_itoa((int) c->width));
	export_element(ppm->header, ft_itoa((int) c->height));
	export_element(ppm->header, "\n255\n");
	ft_strtrim(ppm->header, " ");
	while (c->height--)
	{
		while (c->width--)
		{
			ppm->data[i++] = to_rgb(c->pixels[c->height][c->width]->r);
			ppm->data[i++] = to_rgb(c->pixels[c->height][c->width]->g);
			ppm->data[i++] = to_rgb(c->pixels[c->height][c->width]->b);
		}
	}
	return (ppm);
}
