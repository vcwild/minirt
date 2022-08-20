/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:47:45 by vwildner          #+#    #+#             */
/*   Updated: 2022/08/20 13:47:47 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <light.h>

void	destroy_point_light(t_point_light *l)
{
	free(l->position);
	free(l->intensity);
	free(l);
}

void	destroy_position_args(t_lighting_args *args)
{
	free(args->position);
	free(args->normal_vector);
	free(args->eye_vector);
}

void	destroy_lighting_args(t_lighting_args *args)
{
	destroy_material(args->material);
	destroy_point_light(args->lighting);
	destroy_position_args(args);
	free(args);
}
