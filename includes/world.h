/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:10:04 by itaureli          #+#    #+#             */
/*   Updated: 2022/08/21 13:07:43 by vwildner         ###   ########.fr       */
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

t_world			*new_world(void);
t_objects		*new_objects(void);
t_world			*default_world(void);
t_intersections	*intersect_world(t_world *w, t_ray *r);

int				add_light(t_world *w, t_point_light *pl);
int				add_sphere(t_world *w, t_shape *sphere);

void			destroy_world(t_world *w);

#endif
