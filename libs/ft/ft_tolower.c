/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:16:48 by vwildner          #+#    #+#             */
/*   Updated: 2021/05/29 18:16:49 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	char	dist;
	char	str;

	dist = 'a' - 'A';
	str = (char)c;
	if (str >= 'A' && str <= 'Z')
		str += dist;
	return ((int)str);
}
