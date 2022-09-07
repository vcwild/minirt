/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:47:20 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/07 11:53:31 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <matrix.h>
# include <material.h>

/* ray intersection size */
# define RAY_XS_SIZE 50

/**
 * @brief Definition of available object types by number
 *
 */
typedef enum object_type {
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
	OBJ_SIZE,
}	t_object_type;

/**
 * @brief Ray struct with a starting point origin and a vector direction
 * which says where the ray is going to.
 */
typedef struct s_ray {
	t_point		*origin;
	t_vector	*direction;
}				t_ray;

/**
 * @brief Sphere struct with a center and a radius
 *
 */
typedef struct s_sphere {
	t_point	center;
	double	radius;
}			t_sphere;

/**
 * @brief Plane struct with a point position
 *
 */
typedef struct s_plane {
	t_point		position;
}				t_plane;

/**
 * @brief Cylinder struct with a point position, direction, a radius, a closed
 * a min and a max
 *
 */
typedef struct s_cylinder {
	t_point		position;
	t_vector	*direction;
	double		radius;
	double		min;
	double		max;
	bool		closed;
}				t_cylinder;

/**
 * @brief Shape struct declaration only
 *
 */
typedef struct s_shape	t_shape;

/**
 * @brief Intersection struct with a t (time) value, a object_type and a shape
 *
 */
typedef struct s_intersection {
	t_shape			*shape;
	double			t;
	t_object_type	object_type;
}				t_intersection;

/**
 * @brief Intersections struct with a size, count, is_sorted and an array of
 * intersections
 */
typedef struct s_intersections {
	size_t			count;
	size_t			size;
	int				is_sorted;
	t_intersection	**intersections;
}					t_intersections;

/**
 * @brief Shape struct with auxiliar functions transform, inverse_transform,
 * get_normal, destroy, and intersect. Also has a union of types of shapes.
 *
 */
struct s_shape {
	t_matrix		*transform;
	t_matrix		*inverse_transform;
	t_material		*material;
	union {
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
	};
	t_vector		*(*get_normal)(t_shape *, t_point *);
	void			(*intersect)(t_shape *, t_ray *, t_intersections *);
	void			(*destroy)(t_shape *);
};

/**
 * @brief Discriminant struct with a, b, and c doubles
 *
 */
typedef struct s_discriminant_coefficients {
	double	a;
	double	b;
	double	c;
}			t_disc_coef;

/* create */

/**
 * @brief Create a new shape with values filled with identity matrix
 *
 * @return t_shape* returns a new shape
 */
t_shape			*new_shape(void);

/**
 * @brief Creates a new ray with the given origin and direction.
 *
 * @param origin The origin of the ray.
 * @param direction The direction of the ray.
 * @return t_ray* returns a new ray.
 */
t_ray			*new_ray(t_point *origin, t_vector *direction);

/**
 * @brief Create a list of intersections
 *
 * @return t_intersections* returns a new list of intersections
 */
t_intersections	*new_intersections_list(void);

/**
 * @brief Get the position object
 *
 * @param ray The ray to get the position from.
 * @param distance The distance to the object.
 * @return t_point* returns a new point at the given distance
 */
t_point			*get_position(t_ray *ray, double distance);

/**
 * @brief A function that calculates the normal of a given shape
 * in the given world point.
 *
 * @param shape The shape to get normal value.
 * @param world_point The world point of scene.
 */
t_vector		*get_normal(t_shape *shape, t_point *world_point);

/* sphere */

/**
 * @brief Creates a new sphere shape
 *
 * @return t_shape* returns a new sphere shape
 */
t_shape			*new_sphere(void);

/**
 * @brief Fill values of transform and inverse_transform with given data
 *
 * @param s The shape to fill the values with.
 */
void			set_transform(t_shape *s, t_matrix *mat);

/**
 * @brief Calculate intersection of a ray on the given shape
 *
 * @param shape The shape to calculate the intersection with.
 * @param r The ray to calculate the intersection with.
 * @param xs The array of intersections to add the intersection to.
 */
void			intersect(t_shape *shape, t_ray *r, t_intersections *xs);

/**
 * @brief Get the sphere normal object
 *
 * @param shape The shape to get the normal from.
 * @param point The point to get the normal from.
 * @return t_vector*
 */
t_vector		*get_sphere_normal(t_shape *shape, t_point *point);

/* utils */
/**
 * @brief Get the discriminant of shape to calculate the intersection
 *
 * @param s The sphere to get the discriminant of.
 * @param r The ray to get the discriminant of.
 * @param coef The coefficients of the discriminant.
 * @return double returns the discriminant of the given sphere and ray.
 */
double			get_discriminant(t_sphere *s, t_ray *r, t_disc_coef *coef);

/* intersection */

/**
 * @brief Create a new intersection with the given shape and t value.
 *
 * @param t The t value of the intersection.
 * @param obj The shape of the intersection.
 * @param type The type of the object.
 * @return t_intersection* returns a new intersection.
 */
t_intersection	*new_intersection(double t, t_shape *obj, t_object_type type);

/**
 * @brief Add an intersection to the array of intersections
 *
 * @param xs The array of intersections to add the intersection to.
 * @param new The intersection to add to the array.
 */
void			add_intersection(t_intersections *xs, t_intersection *new);

/**
 * @brief Calculate intersection of a sphere with a ray
 *
 * @param s The sphere to calculate the intersection with.
 * @param r The ray to calculate the intersection with.
 * @param xs The array of intersections to add the intersection to.
 */
void			sphere_intersect(t_shape *s, t_ray *r, t_intersections *xs);

/**
 * @brief Sort the intersections array by t
 *
 * @param xs The array of intersections to sort.
 */
void			sort_intersections(t_intersections *xs);

/* utils */
/**
 * @brief Generates a random double between 0 and INT_MAX
 *
 * @return double random value
 */
double			rand_double(void);

/* destroy */
/**
 * @brief Destroy sphere shape
 *
 * @param s The sphere to destroy.
 */
void			destroy_sphere(t_shape *s);

/**
 * @brief Destroy shape
 *
 */
void			destroy_shape(t_shape *s);

/**
 * @brief Destroy intersection list
 *
 * @param xs The intersection list to destroy.
 */
void			destroy_intersections_list(t_intersections *xs);

/**
 * @brief Destroy a ray
 *
 * @param r The ray to destroy.
 */
void			destroy_ray(t_ray *r);

/* transform */

/**
 * @brief Apply the transformation to the given matrix and ray
 *
 * @param r The ray to transform.
 * @param mat The matrix to transform with.
 * @return t_ray* returns a new ray with the transformed values.
 */
t_ray			*transform(t_ray *r, t_matrix *mat);

/**
 * @brief Check the hit from the intersections array
 *
 * @param xs The array of intersections to check.
 * @return t_intersection* returns the hit from the array.
 */
t_intersection	*hit(t_intersections *xs);

/**
 * @brief Create a new plane shape, a flat surface that extends infinitely in
 * two dimensions xz.
 *
 * @return t_shape* returns a new plane shape.
 */
t_shape			*new_plane(void);

/**
 * @brief Set the material object
 *
 * @param s The shape to set the material to.
 * @param mat The material to set to the shape.
 */
void			set_material(t_shape *s, t_material *mat);

/**
 * @brief Creates a new cylinder
 *
 * @return t_shape* Retuns a dynamically allocated cylinder
 */
t_shape			*new_cylinder(void);

/**
 * @brief Intersects a ray with a cylinder with a given minimum and maximum
 *
 * @param s The cylinder to intersect with.
 * @param r The ray to intersect with.
 * @param xs The list of intersections to map.
 */
void			cylinder_intersect_caps(t_shape *s,
					t_ray *r,
					t_intersections *xs);

/**
 * @brief Intersects a ray with a cylinder with any height.
 * Can handle an unbouded cylinder (no maximum or minimum height)
 *
 * @param s The cylinder to intersect with.
 * @param r The ray to intersect with.
 * @param xs The list of intersections to map.
 */
void			cylinder_intersect(t_shape *s, t_ray *r, t_intersections *xs);

/**
 * @brief Get the cylinder normal object
 *
 * @param s The cylinder to get the normal from.
 * @param p The point to get the normal from.
 * @return t_vector* The normal of the cylinder at the given point.
 */
t_vector		*get_cylinder_normal(t_shape *s, t_point *p);

#endif
