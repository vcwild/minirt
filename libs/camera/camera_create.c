/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:21:17 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/30 00:15:25 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <camera.h>

t_camera	*new_camera(double hsize, double vsize, double fov)
{
	t_camera	*new;
	double		aspect;

	new = (t_camera *)malloc(sizeof(t_camera));
	if (!new)
		return (fprintf(stderr, "Error: Failed creating a camera!"), NULL);
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

t_point	*resolve_point(t_matrix *mat, t_point *p)
{
	t_matrix		*inverse;
	t_vector		*new;

	inverse = invert(mat);
	new = matrix_multiply_tuple(inverse, p);
	free(inverse);
	return (new);
}

t_vector	*resolve_direction(t_point *pixel, t_point *origin)
{
	t_vector	*tmp;
	t_vector	*new;

	tmp = subtract_tuples(pixel, origin);
	new = normalize(tmp);
	free(tmp);
	return (new);
}

t_ray	*ray_to_pixel(t_camera *c, double px, double py)
{
	t_ray		*new;
	t_point		*p;
	t_point		*pixel;
	t_point		*origin;
	t_vector	*direction;

	p = new_point(c->half_width - ((px + 0.5) * c->pixel_size),
			c->half_height - ((py + 0.5) * c->pixel_size),
			-1);
	pixel = resolve_point(c->transform, p);
	free(p);
	p = new_point(0, 0, 0);
	origin = resolve_point(c->transform, p);
	free(p);
	direction = resolve_direction(pixel, origin);
	new = new_ray(origin, direction);
	free(pixel);
	free(origin);
	free(direction);
	return (new);
}
