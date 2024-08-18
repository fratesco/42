/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 07:54:29 by fgolino           #+#    #+#             */
/*   Updated: 2022/11/02 15:05:11 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;
	int		c;

	c = 0;
	while (src[c] != 0)
		c++;
	str = malloc(c + 1);
	c = 0;
	while (src[c] != 0)
	{
		str[c] = src[c];
		c++;
	}
	str[c] = src[c];
	return (str);
}
