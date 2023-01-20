/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:40:47 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/19 18:12:07 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t len)
{
	size_t		i;
	size_t		og_len;

	i = 0;
	og_len = ft_strlen(dst);
	while ((int)(len - og_len - i) >= 0)
	{
		dst[og_len + i] = src[i];
		i++;
	}
	if ((og_len < len) && len > 0)
		dst[og_len + i] = 0;
	return (og_len + len);
}
