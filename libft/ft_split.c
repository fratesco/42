/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:23:17 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/21 14:17:46 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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
		if (s[i] == sep)
			i++;
		else
		{
			len++;
			while (!(s[i] == sep) && s[i])
				i++;
		}
	}
	return (len);
}

void	skip(int *i, int *k, char const *s, char c)
{
	while (s[*i] == c && s[*i])
		(*i)++;
	while (!(s[*i] == c) && s[*i])
	{
		(*k)++;
		(*i)++;
	}
	while (s[*i] == c && s[*i])
		(*i)++;
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		k;
	int		i;
	int		j;
	int		z;

	if (s == 0 || c == 0)
		return (0);
	array = (char **)malloc(sizeof(char *) * (a_size(s, c) + 1));
	i = 0;
	k = 0;
	j = 0;
	z = 0;
	while (s[i])
	{
		skip(&i, &k, s, c);
		array[j++] = s_ncpy(&s[z], k);
		z = i;
		k = 0;
	}
	array[j] = 0;
	return (array);
}
