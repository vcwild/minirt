/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:31:28 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/20 13:31:52 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <light.h>

t_color	*sum_light_components(t_color *diffuse,
		t_color *specular, t_color *ambient)
{
	t_color	*new;
	t_color	*tmp;

	tmp = add_colors_free_args(diffuse, specular);
	new = add_colors_free_args(tmp, ambient);
	return (new);
}
