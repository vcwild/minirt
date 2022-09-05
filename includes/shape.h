/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:26:21 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/04 23:03:55 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include <light.h>

typedef struct s_point3 {
	t_point		*p1;
	t_point		*p2;
	t_point		*p3;
}				t_point3;

typedef struct s_vector3 {
	t_vector	*n1;
	t_vector	*n2;
	t_vector	*n3;
}				t_vector3;

typedef struct s_plane {
	t_point3	points;
	t_vector3	vectors;
}				t_plane;

#endif
