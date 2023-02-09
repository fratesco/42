/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:53:10 by fgolino           #+#    #+#             */
/*   Updated: 2023/02/09 12:03:27 by fgolino          ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	str = (char *)malloc((len + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[len + i] = s2[i];
		i++;
	}
	if (s1)
		free(s1);
	str[len + i] = 0;
	return (str);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}