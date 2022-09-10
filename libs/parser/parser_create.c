/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 22:11:30 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/09 23:47:44 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_rt_props	*new_rt_props(void)
{
	t_rt_props	*new;

	new = malloc(sizeof(t_rt_props));
	if (!new)
		return (NULL);
	new->id = P_SIZE;
	new->line = NULL;
	new->a = malloc(sizeof(t_ambient_props));
	new->c = NULL;
	new->l = NULL;
	new->s = NULL;
	new->status = 0;
	return (new);
}
