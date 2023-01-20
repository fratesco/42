/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:50:22 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/19 15:37:08 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	*ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int	i;

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
