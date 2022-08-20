/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:25:07 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/20 07:01:45 by vwildner         ###   ########.fr       */
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

t_position_args	*new_position_args(t_point *pos, t_vector *normal, t_vector *eye)
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
	return (new);
}

t_color	*lighting(t_lighting_args *args)
{
	t_color		*diffuse;
	t_color		*eff;
	t_color		*specular;
	t_color		*tmp_eff;
	t_tuple		*light_dir;
	t_vector	*light_vector;
	double		product;

	tmp_eff = multiply_colors(args->material->color, args->lighting->intensity);
	light_dir = subtract_tuples(args->lighting->position, args->position);
	light_vector = normalize(light_dir);
	product = dot(light_vector, args->normal_vector);
	diffuse = get_diffuse(args, tmp_eff, product);
	specular = get_specular(args, product, light_vector);
	eff = add_colors_free_args(diffuse, specular);
	free(light_dir);
	free(tmp_eff);
	free(light_vector);
	return (eff);
}
