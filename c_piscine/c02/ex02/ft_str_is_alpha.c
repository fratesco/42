/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:28:52 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/23 23:25:56 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	c;

	c = 0;
	while (str[c] != 0)
	{
		if ((str[c] >= 65 && str[c] <= 90) || (str[c] >= 97 && str[c] <= 122))
			c++;
		else
			return (0);
	}
	return (1);
}