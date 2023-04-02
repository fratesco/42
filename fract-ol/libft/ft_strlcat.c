/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:40:47 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/27 13:10:17 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t len)
{
	size_t		i;
	size_t		og_len;

	i = 0;
	if (!dst && len == 0)
		return (0);
	og_len = ft_strlen(dst);
	if (len <= og_len)
		return (len + ft_strlen(src));
	while ((len - og_len - i) > 1 && src[i])
	{
		dst[og_len + i] = src[i];
		i++;
	}
	dst[og_len + i] = 0;
	return (og_len + ft_strlen(src));
}
