/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:21:17 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/21 23:37:18 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <camera.h>

t_camera	*new_camera(double hsize, double vsize, double fov)
{
	t_camera	*new;
	double		aspect;

	new = (t_camera *)malloc(sizeof(t_camera));
	if (!new)
		return (ft_err("Error\n Failed creating a camera!\n"), NULL);
	new->hsize = hsize;
	new->vsize = vsize;
	new->fov = fov;
	new->transform = identity_matrix();
	aspect = hsize / vsize;
	new->half_width = tan(fov / 2);
	new->half_height = new->half_width / aspect;
	if (aspect < 1)
	{
		new->half_height = tan(fov / 2);
		new->half_width = new->half_height * aspect;
	}
	new->pixel_size = (new->half_width * 2) / hsize;
	return (new);
}

static t_point	*resolve_point(t_matrix *mat, t_point *p)
{
	t_matrix		*inverse;
	t_vector		*new;

	inverse = invert(mat);
	if (!inverse)
		return (ft_err("Error\n Matrix with no determinant!\n"),
			new_vector(0, 0, 0));
	new = matrix_multiply_tuple(inverse, p);
	free(inverse);
	return (new);
}

static t_vector	*resolve_direction(t_point *pixel, t_point *origin)
{
	t_tuple		*tmp;
	t_vector	*new;

	tmp = subtract_tuples(pixel, origin);
	new = normalize(tmp);
	free(tmp);
	return (new);
}

t_ray	*ray_for_pixel(t_camera *c, double width, double height)
{
	t_ray		*new;
	t_point		*p;
	t_point		*pixel;
	t_point		*origin;
	t_vector	*direction;

	p = new_point(c->half_width - (width + 0.5) * c->pixel_size,
			c->half_height - (height + 0.5) * c->pixel_size,
			-1);
	pixel = resolve_point(c->transform, p);
	free(p);
	p = new_point(0, 0, 0);
	origin = resolve_point(c->transform, p);
	free(p);
	direction = resolve_direction(pixel, origin);
	new = new_ray(origin, direction);
	free(pixel);
	return (new);
}
