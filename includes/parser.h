/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:29:01 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/21 22:47:44 by vwildner         ###   ########.fr       */
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

# define P_PROPS_OK 3

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
	t_objects	objects;
}	t_shape_props;

typedef struct s_rt_props {
	t_prop_id			id;
	char				*line;
	t_ambient_props		*a;
	t_camera_props		*c;
	t_light_props		*l;
	t_shape_props		*s;
	int					status;
	unsigned long int	state;
}	t_rt_props;

typedef int	t_dispatcher(t_rt_props *props);

/* read file */
/**
 * @brief Reads a file an parses to a matrix of lines split by newline
 *
 * @param file The file to be read
 * @return char** Returns a matrix of lines
 */
char		**readlines(const char *file);

/**
 * @brief Strips extra spaces from a line
 *
 * @param str The line to be stripped
 * @return int Returns 0 if successful, 1 if not
 */
int			strip_extra_spaces(char *str);

/* dispatcher */
/**
 * @brief The dispatcher function that calls the correct function
 * to parse a line
 *
 * @param file The source file
 * @param props The parser properties struct
 * @return int Returns 0 if successful, 1 if not
 */
int			load_scene(const char *file, t_rt_props *props);

/**
 * @brief Get the prop id object
 *
 * @param line The line to be interpreted
 * @return t_prop_id Returns the prop id enum
 */
t_prop_id	get_prop_id(const char *line);

/* create */
/**
 * @brief Creates a new t_rt_props struct
 *
 * @return t_rt_props* Returns a pointer to the new struct
 */
t_rt_props	*new_rt_props(void);

/* parsers */
/**
 * @brief Parses the ambient light line
 *
 * @param props The parser properties struct
 * @return int Returns 0 if successful, != 0 if not
 */
int			parse_ambient(t_rt_props *props);

/**
 * @brief Parses the camera line
 *
 * @param props The parser properties struct
 * @return int Returns 0 if successful, != 0 if not
 */
int			parse_camera(t_rt_props *props);

/**
 * @brief The light line parser
 *
 * @param props The parser properties struct
 * @return int Returns 0 if successful, != 0 if not
 */
int			parse_light(t_rt_props *props);

/**
 * @brief The plane line parser
 *
 * @param props The parser properties struct
 * @return int Returns 0 if successful, != 0 if not
 */
int			parse_plane(t_rt_props *props);

/**
 * @brief The sphere line parser
 *
 * @param props The parser properties struct
 * @return int Returns 0 if successful, != 0 if not
 */
int			parse_sphere(t_rt_props *props);

/**
 * @brief The cylinder line parser
 *
 * @param props The parser properties struct
 * @return int Returns 0 if successful, != 0 if not
 */
int			parse_cylinder(t_rt_props *props);

/* destroy */
/**
 * @brief Frees a dynamically allcated t_rt_props struct
 *
 * @param props The properties struct to be freed
 */
void		destroy_rt_props(t_rt_props *props);

/* utils */
/**
 * @brief Counts the number of arrays in a matrix
 *
 * @param str The matrix to be counted
 * @return size_t Returns the number of arrays
 */
size_t		count_args(char **str);

/**
 * @brief Parses multiple strings to a double array
 *
 * @param dest The destination array
 * @param origin The origin matrix
 * @param nargs The number of arguments to be parsed
 * @return int Returns 0 if successful, != 0 if not
 */
int			parse_float(double *dest, char **origin, size_t nargs);

/**
 * @brief Prints the arrays from a matrix
 *
 * @param args The matrix to be printed
 */
void		print_args(char **args);

/* setters */
/**
 * @brief Set the shape color object
 *
 * @param shape The shape to be colored
 * @param buf The color buffer to be parsed
 * @return int Returns 0 if successful, != 0 if not
 */
int			set_shape_color(t_shape *shape, char **buf);

/**
 * @brief Set the shape orientation vector
 *
 * @param shape The shape to receive the orientation vector
 * @param buf The buffer to be parsed
 * @return int Returns 0 if successful, != 0 if not
 */
int			set_shape_orientation(t_shape *shape, char **buf);

/* checkers */
/**
 * @brief Verifies if the given color is within the 0-255 range
 *
 * @param args The color buffer to be checked
 * @return int Returns 0 if successful, != 0 if not
 */
int			check_color_range(double *args);

double		to_radians(double degrees);

int			add_shape(t_shape_props *s, t_shape *shape);

int			set_material_props(t_shape *shape, t_rt_props *props);

int			check_within_range(double *args, double min, double max);

#endif
