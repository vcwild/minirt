/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:47:20 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/13 16:15:08 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <matrix.h>

typedef struct s_ray {
	t_tuple	*origin;
	t_tuple	*direction;
}				t_ray;

t_ray	*new_ray(t_tuple *origin, t_tuple *direction);

#endif
