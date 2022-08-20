/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:47:06 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/20 05:47:57 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <light.h>

void	light_destroy(t_point_light *l)
{
	free(l->position);
	free(l->intensity);
	free(l);
}
