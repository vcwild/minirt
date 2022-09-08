/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_atof.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vwildner <vwildner@student.42sp.org.br>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/09/07 21:00:46 by vwildner		  #+#	#+#			 */
/*   Updated: 2022/09/07 21:00:50 by vwildner		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

static double	raw_atof(const char *str, double acc)
{
	double	scale;

	scale = 10;
	acc = acc * 10.0 + (*str - '0');
	while (*(++str))
	{
		if (scale < 10)
		{
			scale /= 10;
			acc += (*str - '0') * scale;
			continue ;
		}
		if (*str == '.')
		{
			scale /= 10;
			continue ;
		}
		acc = acc * 10.0 + (*str - '0');
	}
	return (acc);
}

double	ft_atof(const char *str)
{
	double	final;
	int		neg;

	neg = 1;
	if (*str == '-')
	{
		str++;
		neg = -1;
	}
	final = raw_atof(str, 0);
	return (final * neg);
}
