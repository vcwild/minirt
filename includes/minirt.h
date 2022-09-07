/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:56:05 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/07 20:13:28 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <math.h>

# include "../libs/mlx_linux/mlx.h"
# include <canvas.h>
# include <ray.h>
# include <camera.h>

/* constants */
# define RT_WIDTH 100
# define RT_HEIGHT 100

/* structs */
typedef struct s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_rt {
	t_camera		*camera;
	t_canvas		*canvas;
	t_image			*image;
	t_point			*cam_position;
	t_vector		*cam_direction;
	t_world			*world;
	void			*mlx;
	void			*window;
}					t_rt;

t_rt	*new_ray_tracer(void);
void	destroy_ray_tracer(t_rt *rt);

#endif
