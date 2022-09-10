/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 22:11:47 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/09 23:55:00 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	destroy_ambient(t_ambient_props *a)
{
	free(a->color);
	free(a);
}

void	destroy_rt_props(t_rt_props *props)
{
	destroy_ambient(props->a);
	if (props->c)
		free(props->c);
	if (props->l)
		free(props->l);
	if (props->s)
		free(props->s);
	free(props);
}
