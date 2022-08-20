/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_specular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 06:24:27 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/20 06:42:16 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <light.h>

static t_color	*new_scalar_specular(t_point_light *l,
		t_material *mat, double scalar)
{
	t_color	*new;
	t_color	*tmp;
	double	scalar;

	tmp = multiply_scalar_color(l->intensity, mat->specular);
	new = multiply_scalar_color(tmp, scalar);
	free(tmp);
	return (new);
}

t_color	*get_specular(t_lighting_args *args, double dot_normal, t_vector *v)
{
	t_color	*tmp;
	double	dot_eye;
	double	scalar;
	t_tuple	*reflect;

	if (dot_normal < 0)
		return (new_color(0, 0, 0));
	tmp = negate_tuple(v);
	reflect = reflect_vector(tmp, args->normal_vector);
	dot_eye = dot(reflect, args->eye_vector);
	free(tmp);
	free(reflect);
	if (dot_eye <= 0)
		return (new_color(0, 0, 0));
	scalar = pow(dot_eye, args->material->shininess);
	return (new_scalar_specular(args->lighting, args->material, scalar));
}
