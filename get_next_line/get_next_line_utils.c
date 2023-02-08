/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:53:10 by fgolino           #+#    #+#             */
/*   Updated: 2023/02/08 18:55:30 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while (len && s[i + start])
	{
		sub[i] = s[i + start];
		len--;
		i++;
	}
	sub[i] = 0;
	return (sub);
}