/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:03:06 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/17 18:04:42 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buffer, int byte, int len)
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
