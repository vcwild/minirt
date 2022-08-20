/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_diffuse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 06:42:43 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/20 06:46:38 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <light.h>

t_color	*get_diffuse(t_lighting_args *args, t_color *eff, double dot_normal)
{
	t_color	*tmp;
	t_color	*new;

	if (dot_normal < 0)
		return (new_color(0, 0, 0));
	tmp = multiply_scalar_color(eff, args->material->diffuse);
	new = multiply_scalar_color(tmp, dot_normal);
	free(tmp);
	return (new);
}
