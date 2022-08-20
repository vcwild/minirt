/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:25:35 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/20 05:02:50 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <material.h>

t_material	*new_material(void)
{
	t_material	*material;

	material = (t_material *)malloc(sizeof(t_material));
	material->color = new_color(1, 1, 1);
	material->ambient = 0.1;
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->shininess = 200.0;
	return (material);
}
