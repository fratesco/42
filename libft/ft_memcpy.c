/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:47:30 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/19 18:27:03 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t len)
{
	int	i;

	i = 0;
	while (len)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
		len--;
	}
	return (dst);
}
