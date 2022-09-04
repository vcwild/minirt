/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:10:04 by itaureli          #+#    #+#             */
/*   Updated: 2022/09/05 19:55:58 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include <light.h>
# include <stdbool.h>

/**
 * @brief Struct of objects
 *
 */
typedef struct s_objects {
	int				total;
	int				sphere_count;
	t_list			*spheres;
}	t_objects;

/**
 * @brief The world struct with all the objects and lights.
 *
 */
typedef struct s_world {
	t_objects	objects;
	t_list		*lights;
}	t_world;

/**
 * @brief Struct with precomputed values for the intersection.
 *
 */
typedef struct s_computations {
	double			t;
	t_object_type	object_type;
	t_shape			*shape;
	t_point			*point;
	t_point			*over_point;
	t_vector		*eyev;
	t_vector		*normalv;
	bool			inside;
}					t_computations;

/**
 * @brief Creates a new empty world, with no objects and light source.
 *
 * @return t_world* The new world.
 */
t_world			*new_world(void);

/**
 * @brief Creates a new empty object list.
 *
 * @return t_objects* The new object list.
 */
t_objects		*new_objects(void);

/**
 * @brief Creates a new world with a single light source and two spheres.
 *
 * @return t_world* The new default world.
 */
t_world			*default_world(void);

/**
 * @brief A function that calculates the intersection of a ray into
 * objects in a world.
 *
 * @param w The world to calculate the intersection in.
 * @param r The ray to calculate the intersection for.
 * @return t_intersections* Sortered list of intersections in the
 * world.
 */
t_intersections	*intersect_world(t_world *w, t_ray *r);

/**
 * @brief Add a new light to the world.
 *
 * @param w The world to add the light to.
 * @param pl The light to add.
 * @return int 0 if success, -1 if error.
 */
int				add_light(t_world *w, t_point_light *pl);

/**
 * @brief Add a new sphere to the world.
 *
 * @param w The world to add the sphere to.
 * @param sphere The sphere to add.
 * @return int 0 if success, -1 if error.
 */
int				add_sphere(t_world *w, t_shape *sphere);

/**
 * @brief Precomputes the intersection values for the given intersection.
 *
 * @param x The intersection to precompute.
 * @param r The ray that intersected the intersection.
 * @return t_computations* New data structure encapsulating some precomputed
 * information about the intersection.
 */
t_computations	*prepare_computations(t_intersection *x, t_ray *r);

/**
 * @brief Destroys a world and all its objects and lights.
 *
 * @param w The world to destroy.
 */
void			destroy_world(t_world *w);

/**
 * @brief Destroys precomputed intersection data.
 *
 * @param c The data to destroy.
 */
void			destroy_computations(t_computations *c);

/**
 * @brief Checks if a point is in shadow.
 *
 * @param w The world to check.
 * @param c The precomputed intersection data.
 * @return t_color* The color of the intersection encapsulated in the
 * precomputed data.
 */
t_color			*shade_hit(t_world *w, t_computations *c);

/**
 * @brief Get the color from a world at a given point.
 *
 * @param w The world to get the color from.
 * @param r The ray to get the color from.
 * @return t_color* The color at the given point.
 */
t_color			*get_color(t_world *w, t_ray *r);

/**
 * @brief Check if a point is in shadow.
 *
 * @param w The world to check.
 * @param p The point to check.
 * @param pl The light to check.
 * @return true if the point is in shadow.
 */
bool			is_shadowed(t_world *w, t_point *p, t_point_light *pl);

#endif
