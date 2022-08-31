/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:05:01 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/31 17:03:54 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <world.h>

typedef struct s_camera
{
	double		hsize;
	double		vsize;
	double		fov;
	double		pixel_size;
	double		half_width;
	double		half_height;
	t_matrix	*transform;
}			t_camera;

/**
 * @brief Creates a new camera with the given parameters.
 *
 * @param hsize The horizontal size of the canvas.
 * @param vsize The vertical size of the canvas.
 * @param fov The field of view of the camera.
 * @return t_camera* The new camera.
 */
t_camera	*new_camera(double hsize, double vsize, double fov);

/**
 * @brief Destroys the given camera.
 *
 * @param c The camera to destroy.
 */
void		destroy_camera(t_camera *c);

/**
 * @brief Constructs a ray that passes at the given coordinates
 *
 * @param c The camera.
 * @param width The x coordinate of the pixel.
 * @param height The y coordinate of the pixel.
 * @return t_ray*
 */
t_ray		*ray_for_pixel(t_camera *c, double width, double height);

/**
 * @brief Renders the canvas for a given camera perspective
 *
 * @param c The camera to render.
 * @param w The world to render.
 * @return t_canvas*
 */
t_canvas	*render(t_camera *c, t_world *w);

/**
 * @brief Set the camera transform object
 *
 * @param c The camera to set the transform.
 * @param transform The transform matrix.
 */
void		set_camera_transform(t_camera *c, t_matrix *transform);

#endif
