/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:47:30 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/28 10:32:23 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	int	i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (len)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
		len--;
	}
	return (dst);
}
