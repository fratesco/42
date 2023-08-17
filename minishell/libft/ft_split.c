/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:23:17 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/28 11:56:47 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*s_ncpy(char const *s, int end)
{
	char	*scpy;
	int		i;

	i = 0;
	scpy = (char *)malloc(sizeof(char) * (end + 1));
	while (i < end)
	{
		scpy[i] = s[i];
		i++;
	}
	scpy[i] = 0;
	return (scpy);
}

int	a_size(char const *s, char sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		if (!(s[i] == sep) && s[i])
		{
			len++;
			i++;
		}
		while (!(s[i] == sep) && s[i])
			i++;
	}
	return (len);
}

void	skip(int *num, char const *s, char c)
{
	while (s[num[0]] == c && s[num[0]])
		(num[0])++;
	num[1] = num[0];
	while (!(s[num[0]] == c) && s[num[0]])
	{
		(num[3])++;
		(num[0])++;
	}
	while (s[num[0]] == c && s[num[0]])
		(num[0])++;
}

char	**prevent_leak(void *str)
{
	free (str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		*num;

	num = ft_calloc(4, sizeof(int));
	if (s == 0 || !num)
		return (prevent_leak(num));
	if (s[0] != 0)
	{
		array = (char **)malloc(sizeof(char *) * (a_size(s, c) + 1));
		if (!array)
			return (0);
	}
	while (s[num[0]] && a_size(s, c) > 0)
	{
		skip(num, s, c);
		array[num[2]++] = s_ncpy(&s[(num[1])], num[3]);
		num[1] = num[0];
		num[3] = 0;
	}
	if (!s[0])
		array = (char **)malloc(sizeof(char *));
	array[num[2]] = 0;
	prevent_leak(num);
	return (array);
}
