/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:29:01 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/16 15:57:11 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include <stdio.h>
# include <canvas.h>
# include <camera.h>

/* constants */
# define PARSER_BUFFER_SIZE 99

/* types */
typedef enum e_prop_id {
	P_AMBIENT,
	P_CAMERA,
	P_LIGHT,
	P_PLANE,
	P_SPHERE,
	P_CYLINDER,
	P_SIZE
}	t_prop_id;

typedef struct s_ambient_props {
	double	ratio;
	t_color	*color;
}	t_ambient_props;

typedef struct s_camera_props {
	t_point		*origin;
	t_vector	*direction;
	double		fov;
}	t_camera_props;

typedef struct s_light_props {
	t_point_light	*pl;
	t_color			*color;
	double			brightness;
}	t_light_props;

typedef struct s_shape_props {
	t_list	*shapes;
}	t_shape_props;

typedef struct s_rt_props {
	t_prop_id			id;
	char				*line;
	t_ambient_props		*a;
	t_camera_props		*c;
	t_light_props		*l;
	t_shape_props		*s;
	int					status;
}	t_rt_props;

typedef int	t_dispatcher(t_rt_props *props);

/* read file */
char		**readlines(const char *file);
int			strip_extra_spaces(char *str);

/* dispatcher */
int			load_scene(const char *file, t_rt_props *props);
t_prop_id	get_prop_id(const char *line);

/* create */
t_rt_props	*new_rt_props(void);

/* parsers */
int			parse_ambient(t_rt_props *props);
int			parse_camera(t_rt_props *props);
int			parse_light(t_rt_props *props);
int			parse_plane(t_rt_props *props);
int			parse_sphere(t_rt_props *props);
int			parse_cylinder(t_rt_props *props);

/* destroy */
void		destroy_rt_props(t_rt_props *props);

/* utils */
size_t		count_args(char **str);
int			parse_float(double *dest, char **origin, size_t nargs);
void		print_args(char **args);

/* setters */
int			set_shape_color(t_shape *shape, char **buf);
int			set_shape_orientation(t_shape *shape, char **buf);

#endif
