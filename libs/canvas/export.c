/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:37:52 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/01 21:49:22 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <canvas.h>

typedef struct s_ppm {
	char	*header;
	char	*data;
}	t_ppm;


t_ppm	*canvas_to_ppm(t_canvas *c)
{
	t_ppm	ppm;

	ppm.header = ft_strdup("P3\n");
	ppm.header = ft_strjoin(ppm.header, ft_itoa(c->width));
	ppm.header = ft_strjoin(ppm.header, " ");
	ppm.header = ft_strjoin(ppm.header, ft_itoa(c->height));
	ppm.header = ft_strjoin(ppm.header, "\n255\n");
	while (c->height--)
	{
		while (c->width--)
		{
			ppm.data = ft_strjoin(ppm.data, ft_itoa(c->pixels[c->height][c->width]->r));
			ppm.data = ft_strjoin(ppm.data, " ");
			ppm.data = ft_strjoin(ppm.data, ft_itoa(c->pixels[c->height][c->width]->g));
			ppm.data = ft_strjoin(ppm.data, " ");
			ppm.data = ft_strjoin(ppm.data, ft_itoa(c->pixels[c->height][c->width]->b));
			ppm.data = ft_strjoin(ppm.data, " ");
		}
		ppm.data = ft_strjoin(ppm.data, "\n");
	}
	return (&ppm);
}
