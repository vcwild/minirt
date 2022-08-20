/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:26:30 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/20 17:32:11 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include <material.h>

typedef struct s_point_light {
	t_point		*position;
	t_color		*intensity;
}				t_point_light;

typedef struct s_lighting_args {
	t_material		*material;
	t_point_light	*lighting;
	t_vector		*eye_vector;
	t_vector		*normal_vector;
	t_point			*position;
}					t_lighting_args;

typedef struct s_position_args {
	t_point		*position;
	t_vector	*normal_vector;
	t_vector	*eye_vector;
}				t_position_args;

t_point_light	*new_point_light(t_point *p, t_color *c);
t_position_args	*new_position_args(t_point *pos,
					t_vector *normal, t_vector *eye);
t_lighting_args	*new_light_args(t_material *m,
					t_point_light *l, t_position_args *args);

t_color			*get_diffuse(t_lighting_args *args,
					t_color *eff, double dot_normal);

t_color			*get_specular(t_lighting_args *args,
					t_vector *v, double dot_normal);

t_color			*lighting(t_lighting_args *args);

void			destroy_lighting_args(t_lighting_args *args);
void			destroy_point_light(t_point_light *l);

t_color			*sum_light_components(t_color *diffuse,
					t_color *specular, t_color *ambient);
#endif
