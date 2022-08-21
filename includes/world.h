/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:10:04 by itaureli          #+#    #+#             */
/*   Updated: 2022/08/21 15:41:20 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include <light.h>

typedef struct s_objects {
	int				total;
	int				sphere_count;
	t_list			*spheres;
}	t_objects;

typedef struct s_world {
	t_objects	objects;
	t_list		*lights;
}	t_world;

typedef struct s_computations {
	double			t;
	t_object_type	object_type;
	t_shape			*shape;
	t_point			*point;
	t_vector		*eyev;
	t_vector		*normalv;
}					t_computations;

t_world			*new_world(void);
t_objects		*new_objects(void);
t_world			*default_world(void);
t_intersections	*intersect_world(t_world *w, t_ray *r);

int				add_light(t_world *w, t_point_light *pl);
int				add_sphere(t_world *w, t_shape *sphere);

t_computations	*prepare_computations(t_intersection *x, t_ray *r);

void			destroy_world(t_world *w);
void			destroy_computations(t_computations *c);

#endif
