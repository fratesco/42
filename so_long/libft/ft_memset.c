/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:03:06 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/19 14:58:41 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buffer, int byte, size_t len)
{
	int	i;

	i = 0;
	while (len)
	{
		((char *)buffer)[i] = ((unsigned char) byte);
		i++;
		len--;
	}
	return (buffer);
}
