/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:17:36 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/24 00:31:07 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	c;

	c = 0;
	while (str[c] != 0)
	{
		if (str[c] >= 97 && str[c] <= 122)
			str[c] = str[c] - 32;
		c++;
	}
	return (str);
}
