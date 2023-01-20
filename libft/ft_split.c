/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:23:17 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/19 16:24:57 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*str_ncpy(char *str, int end)
{
	char	*strcpy;
	int		i;

	i = 0;
	strcpy = (char *)malloc(sizeof(char) * (end + 1));
	while (i < end)
	{
		strcpy[i] = str[i];
		i++;
	}
	strcpy[i] = 0;
	return (strcpy);
}

int	is_sep(char str, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (str == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	a_size(char *str, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (is_sep(str[i], sep))
			i++;
		else
		{
			len++;
			while (!((is_sep(str[i], sep))) && str[i])
				i++;
		}
	}
	return (len);
}

void	skip(int *i, int *k, char *str, char *charset)
{
	while ((is_sep(str[*i], charset)) && str[*i])
		(*i)++;
	while (!(is_sep(str[*i], charset)) && str[*i])
	{
		(*k)++;
		(*i)++;
	}
	while ((is_sep(str[*i], charset)) && str[*i])
		(*i)++;
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		k;
	int		i;
	int		j;
	int		z;

	if (str == 0 || charset == 0)
		return (0);
	array = (char **)malloc(sizeof(char *) * (a_size(str, charset) + 1));
	i = 0;
	k = 0;
	j = 0;
	z = 0;
	while (str[i])
	{
		skip(&i, &k, str, charset);
		array[j++] = str_ncpy(&str[z], k);
		z = i;
		k = 0;
	}
	array[j] = 0;
	return (array);
}
