/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:16:54 by vwildner          #+#    #+#             */
/*   Updated: 2021/05/29 18:16:55 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	char	dist;
	char	str;

	dist = 'a' - 'A';
	str = (char)c;
	if (str >= 'a' && str <= 'z')
		str -= dist;
	return ((int)str);
}
