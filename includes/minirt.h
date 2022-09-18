/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:56:05 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/10 12:29:03 by itaureli         ###   ########.fr       */
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
# include <parser.h>
# include <X11/X.h>
# include <X11/keysym.h>

/* constants */
# define RT_WIDTH 300
# define RT_HEIGHT 300
# define KEY_ESC 65307
# define EVENT_KEY_PRESS	2
# define EVENT_X_WIN_PRESS	17
# define NAME				"miniRT"

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
	t_image			image;
	t_point			*cam_position;
	t_vector		*cam_direction;
	t_world			*world;
	void			*mlx;
	void			*window;
}					t_rt;

t_rt	*new_ray_tracer(void);
void	destroy_ray_tracer(t_rt *rt);

/* Hooks */
int		close_window(t_rt *rt);
int		key_hooks(t_rt *rt);

void	run_mlx_window(t_rt *rt);
void	render_canvas(t_rt *rt);
#endif
