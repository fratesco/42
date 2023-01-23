/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:50:22 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/23 18:17:18 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != 0 && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = 0;
	i = 0;
	while (src[i] != 0)
		i++;
	return (i);
}
