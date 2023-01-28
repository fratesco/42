/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:31:30 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/28 11:17:57 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *str1)
{
	size_t	len;
	char	*str2;

	len = ft_strlen(str1);
	str2 = (char *)malloc((len + 1) * sizeof(char));
	if (str2 == 0)
		return (0);
	len = 0;
	while (str1[len])
	{
		str2[len] = str1[len];
		len++;
	}
	str2[len] = 0;
	return (str2);
}
