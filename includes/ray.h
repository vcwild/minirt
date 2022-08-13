/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:47:20 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/13 16:45:53 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <matrix.h>

typedef struct s_ray {
	t_point		*origin;
	t_vector	*direction;
}				t_ray;

t_ray	*new_ray(t_point *origin, t_vector *direction);
t_point	*get_position(t_ray *ray, double distance);

#endif
