/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:26:30 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/21 11:43:19 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include <material.h>
# include <ray.h>

/**
 * @brief Structure for a point light.
 *
 */
typedef struct s_point_light {
	t_point		*position;
	t_color		*intensity;
}				t_point_light;

/**
 * @brief Struct to hold lighting arguments.
 *
 */
typedef struct s_lighting_args {
	t_material		*material;
	t_point_light	*lighting;
	t_vector		*eye_vector;
	t_vector		*normal_vector;
	t_point			*position;
}					t_lighting_args;

/**
 * @brief The positional arguments.
 *
 */
typedef struct s_position_args {
	t_point		*position;
	t_vector	*normal_vector;
	t_vector	*eye_vector;
}				t_position_args;

/**
 * @brief Create a new point light.
 *
 * @param p The position of the light.
 * @param intensity The intensity of the light.
 * @return t_point_light* The new light.
 */
t_point_light	*new_point_light(t_point *p, t_color *intensity);

/**
 * @brief The positional arguments initalizer.
 *
 * @param pos The initial position of the object.
 * @param normal The normal vector.
 * @param eye The eye vector.
 * @return t_position_args* Returns the positional arguments.
 */
t_position_args	*new_position_args(t_point *pos,
					t_vector *normal, t_vector *eye);

/**
 * @brief Instantiates a new struct of lighting arguments.
 *
 * @param m The material of the object.
 * @param l The point of light of the object.
 * @param args The initial positional arguments of the object.
 * @return t_lighting_args* Returns the lighting arguments.
 */
t_lighting_args	*new_light_args(t_material *m,
					t_point_light *l, t_position_args *args);

/**
 * @brief Get the diffuse color of the object.
 *
 * @param args The lighting arguments.
 * @param eff The effective color.
 * @param dot_normal The dot normal product of the normal and the eye.
 * @return t_color* Returns the diffuse color.
 */
t_color			*get_diffuse(t_lighting_args *args,
					t_color *eff, double dot_normal);

/**
 * @brief Get the specular color of the object.
 *
 * @param args The lighting arguments.
 * @param v The vector to reflect.
 * @param dot_normal The dot normal product of the normal and the eye.
 * @return t_color* Returns the specular color.
 */
t_color			*get_specular(t_lighting_args *args,
					t_vector *v, double dot_normal);

/**
 * @brief Get the color for the sum of ambient, specular and
 * diffuse components for the object.
 *
 * @param args The initial lighting arguments.
 * @return t_color* Returns the sum of the lighting components.
 */
t_color			*lighting(t_lighting_args *args);

/**
 * @brief Destroys the lighting arguments.
 *
 * @param args The lighting arguments.
 */
void			destroy_lighting_args(t_lighting_args *args);

/**
 * @brief Destroy a point light.
 *
 * @param light The light to destroy.
 */
void			destroy_point_light(t_point_light *l);

/**
 * @brief Get the sum of the ambient, specular and diffuse components.
 *
 * @param diffuse The diffuse component.
 * @param specular The specular component.
 * @param ambient The ambient component.
 * @return t_color* Returns the sum of the light components.
 */
t_color			*sum_light_components(t_color *diffuse,
					t_color *specular, t_color *ambient);
#endif
