/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 07:54:29 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/24 08:00:01 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;
	int		c;

	while (src[c] != 0)
		c++;
	str = malloc(c);
	c = 0;
	while (src[c] != 0)
	{
		str[c] = src[c];
		c++;
	}
	str[c] = src[c];
	return (str);
}
