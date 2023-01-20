/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:31:30 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/19 19:20:10 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str1)
{
	size_t	len;
	char	*str2;

	len = ft_strlen(str1);
	str2 = (char *)malloc((len + 1) * sizeof(char));
	if (str2 == 0)
		return (0);
	while (len + 1)
	{
		str2[len] = str1[len];
		len--;
	}
	return (str2);
}
