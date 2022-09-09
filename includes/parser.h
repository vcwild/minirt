/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:29:01 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/09 15:38:59 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <libft.h>
# include <fcntl.h>
# include <stdio.h>

# define PARSER_BUFFER_SIZE 99

typedef enum prop_name {
	P_A,
	P_C,
	P_L,
	P_pl,
	P_sp,
	P_cy,
	P_SIZE
}	t_prop_name;

typedef int	t_dispatcher(t_rt_props *cmd);

typedef struct s_rt_props {
	int			argc;
	int			fd;
	char		**argv;
	t_list		**envp;
	t_prop_name	prop_name;
	int			status;
}	t_rt_props;

char	**readlines(const char *file);
int		strip_extra_spaces(char *str);
int		borrow_line(char *line, char **acc, int index);

#endif
