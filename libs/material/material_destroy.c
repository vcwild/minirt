/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:08:17 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/20 05:08:30 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <material.h>

void	destroy_material(t_material *m)
{
	free(m->color);
	free(m);
}
