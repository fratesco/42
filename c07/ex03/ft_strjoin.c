/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:01:19 by fgolino           #+#    #+#             */
/*   Updated: 2022/11/01 11:56:16 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	tot_length(char **strs, int size)
{
	int	i;
	int	tot_len;

	i = 0;
	tot_len = 0;
	while (i < size)
	{
		tot_len += str_len(strs[i]);
		i++;
	}
	return (tot_len);
}

char	*str_cat(char *str1, char *str2, int len)
{
	int	i;

	i = 0;
	while (str2[i])
	{
		str1[len + i] = str2[i];
		i++;
	}
	str1[len + i] = 0;
	return (str1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;
	int		tot_len;

	if (size == 0)
	{
		str = (char *)malloc(sizeof(char) * 1);
		return (str);
	}
	tot_len = tot_length(strs, size);
	tot_len += (str_len(sep) * (size - 1)) + 1;
	str = (char *)malloc(sizeof(char) * tot_len);
	while (tot_len > 0)
		str[--tot_len] = 0;
	i = 0;
	while (i < size)
	{
		str_cat(str, strs[i++], str_len(str));
		if (i < size)
			str_cat(str, sep, str_len(str));
	}
	return (str);
}
