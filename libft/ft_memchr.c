/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:12:56 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/28 10:56:58 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	void	*tmp;

	if (n == 0)
		return (0);
	while (n > 0)
	{
		if ((*(unsigned char *)str) == (unsigned char) c)
			return (tmp = (void *)str);
		n--;
		str++;
	}
	return (0);
}
