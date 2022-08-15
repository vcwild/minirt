/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:47:20 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/15 20:29:41 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <matrix.h>

/* ray intersection size */
# define RAY_XS_SIZE 50

typedef enum object_type {
	OBJ_SPHERE,
	OBJ_SIZE,
}	t_object_type;

typedef struct s_ray {
	t_point		*origin;
	t_vector	*direction;
}				t_ray;

typedef struct s_sphere {
	t_point	center;
	double	radius;
}			t_sphere;

typedef union s_properties
{
	t_sphere	sphere;
}	t_properties;

typedef struct s_shape	t_shape;

typedef struct s_intersection {
	t_shape			*shape;
	double			t;
	t_object_type	object_type;
}				t_intersection;

typedef struct s_intersections {
	size_t			count;
	size_t			size;
	int				is_sorted;
	t_intersection	**intersections;
}					t_intersections;

struct s_shape {
	t_matrix		*transform;
	t_matrix		*inverse_transform;
	union {
		t_sphere	sphere;
	};
	t_vector		*(*get_normal)(t_shape *, t_point *);
	void			(*intersect)(t_shape *, t_ray *, t_intersections *);
	void			(*destroy)(t_shape *);
};

typedef struct s_discriminant_coefficients {
	double	a;
	double	b;
	double	c;
}			t_disc_coef;

/* create */
t_shape			*new_shape(void);
t_ray			*new_ray(t_point *origin, t_vector *direction);
t_point			*get_position(t_ray *ray, double distance);

/* sphere */
t_shape			*new_sphere(void);
void			set_transform(t_shape *s, t_matrix *mat);
void			sphere_intersect(t_shape *s, t_ray *r, t_intersections *xs);
void			intersect(t_shape *shape, t_ray *r, t_intersections *xs);
t_vector		*get_sphere_normal(t_shape *shape, t_point *point);

/* utils */
double			get_discriminant(t_sphere *s, t_ray *r, t_disc_coef *coef);

/* intersection */
t_intersection	*new_intersection(double t, t_shape *obj, t_object_type type);
void			add_intersection(t_intersections *xs, t_intersection *new);
void			sphere_intersect(t_shape *s, t_ray *r, t_intersections *xs);
void			sort_intersections(t_intersections *xs);

/* utils */
double			rand_double(void);

/* destroy */
void			destroy_sphere(t_shape *s);
void			destroy_intersections_list(t_intersections *xs);
void			destroy_ray(t_ray *r);

/* transform */
t_ray			*transform(t_ray *r, t_matrix *mat);

#endif
