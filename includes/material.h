/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:23:35 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/20 17:51:28 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include <canvas.h>

typedef struct s_material {
	t_color	*color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}			t_material;

/**
 * @brief Create a new material with default values.
 *
 * @return t_material* The new material struct created.
 */
t_material	*new_material(void);

/**
 * @brief Frees the memory of the material struct.
 *
 * @param m The material struct to free.
 */
void		destroy_material(t_material *m);

#endif
