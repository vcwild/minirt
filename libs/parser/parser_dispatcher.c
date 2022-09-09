/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dispatcher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:48:17 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/09 15:48:18 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	parse_error(t_rt_props *props)
{
	(void)props;
	fprintf(stderr, "Error: Invalid file\n");
	return (-1);
}

static t_dispatcher	*locate_prop(t_prop_name identifier)
{
	static t_dispatcher	*table[P_SIZE + 1];

	table[P_A] = parse_a;
	table[P_C] = parse_c;
	table[P_L] = parse_l;
	table[P_pl] = parse_pl;
	table[P_sp] = parse_sp;
	table[P_cy] = parse_cy;
	table[P_SIZE] = parse_error;
	return (table[identifier]);
}

int	run(t_rt_props *props)
{
	int				status;
	t_dispatcher	*parse;

	parse = locate_prop(props->prop_name);
	status = (*parse)(props);
	return (status);
}
