/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:06:42 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/27 13:11:48 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t		i;
	size_t		j;
	int			lt;

	i = 0;
	if (str == 0 && len == 0)
		return (0);
	if (to_find[0] == 0)
		return (str);
	while (str[i] && i < len)
	{
		if (str[i] == to_find[0])
		{
			j = i;
			lt = 0;
			while (str[j] == to_find[lt] && to_find[lt++] && j < len)
			{
				j++;
				if (to_find[lt] == 0)
					return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}
