/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:13:02 by vwildner          #+#    #+#             */
/*   Updated: 2021/05/29 18:14:35 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*element;

	if (*lst == NULL)
		return ;
	element = *lst;
	while (element != NULL)
	{
		tmp = element->next;
		ft_lstdelone(element, del);
		element = tmp;
	}
	*lst = NULL;
}
