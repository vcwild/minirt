/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:31:06 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/18 19:34:00 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int	add_shape(t_shape_props *s, t_shape *shape)
{
	t_list	*new;

	new = ft_lstnew(shape);
	if (!new)
	{
		fprintf(stderr, "Error: There was an error adding shape!");
		return (1);
	}
	ft_lstadd_back(&s->objects.spheres, new);
	s->objects.sphere_count += 1;
	s->objects.total += 1;
	return (0);
}
