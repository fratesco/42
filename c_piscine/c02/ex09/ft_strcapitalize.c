/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:21:52 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/20 18:13:50 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	c;
	int	a;

	c = 0;
	a = 0;
	while (str[c] != 0)
	{
		if (a == 0 && str[c] >= 97 && str[c] <= 122)
		{
			str[c] = str[c] - 32;
			a = 1;
		}
		else if (a == 0 && str[c] >= 65 && str[c] <= 90)
			a = 1;
		else if (a == 1 && str[c] >= 65 && str[c] <= 90)
			str[c] = str[c] + 32;
		else if (str[c] >= 48 && str[c] <= 57)
			a = 1;
		else if ((str[c] > 0 && str[c] < 65) || (str[c] > 90 && str[c] < 97))
			a = 0;
		else if (str[c] > 122)
			a = 0;
		c++;
	}
	return (str);
}
