/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:56:59 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/25 12:05:03 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	if (!s)
		return (0);
	i = 0;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == 0)
		return (0);
	while (len && s[i + start] && start <= ft_strlen(s))
	{
		sub[i] = s[i + start];
		len--;
		i++;
	}
	sub[i] = 0;
	return (sub);
}
