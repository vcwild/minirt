/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:25:07 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/20 17:22:11 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <light.h>

t_point_light	*new_point_light(t_point *p, t_color *c)
{
	t_point_light	*new;

	new = (t_point_light *)malloc(sizeof(t_point_light));
	new->position = p;
	new->intensity = c;
	return (new);
}

t_position_args	*new_position_args(
	t_point *pos, t_vector *normal, t_vector *eye
)
{
	t_position_args	*new;

	new = (t_position_args *)malloc(sizeof(t_position_args));
	new->position = pos;
	new->normal_vector = normal;
	new->eye_vector = eye;
	return (new);
}

t_lighting_args	*new_light_args(t_material *m,
		t_point_light *l, t_position_args *args)
{
	t_lighting_args	*new;

	new = (t_lighting_args *)malloc(sizeof(t_lighting_args));
	new->material = m;
	new->lighting = l;
	new->position = args->position;
	new->normal_vector = args->normal_vector;
	new->eye_vector = args->eye_vector;
	free(args);
	return (new);
}

static t_color	*_lighting(t_lighting_args *args,
	t_color *eff, t_vector *light_vector, double dot_normal
)
{
	t_color		*ambient;
	t_color		*diffuse;
	t_color		*specular;

	ambient = multiply_scalar_color(eff, args->material->ambient);
	diffuse = get_diffuse(args, eff, dot_normal);
	specular = get_specular(args, light_vector, dot_normal);
	free(eff);
	free(light_vector);
	return (sum_light_components(diffuse, specular, ambient));
}

t_color	*lighting(t_lighting_args *args)
{
	t_color		*eff;
	t_tuple		*light_dir;
	t_vector	*light_vector;
	double		dot_normal;

	eff = multiply_colors(args->material->color, args->lighting->intensity);
	light_dir = subtract_tuples(args->lighting->position, args->position);
	light_vector = normalize(light_dir);
	free(light_dir);
	dot_normal = dot(light_vector, args->normal_vector);
	return (_lighting(args, eff, light_vector, dot_normal));
}
