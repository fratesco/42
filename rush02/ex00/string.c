/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:51:24 by ihhrabar          #+#    #+#             */
/*   Updated: 2022/10/29 18:51:29 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

char	*new_str(char *str)
{
	int		length;
	char	*result;
	int		i;

	length = str_length(str);
	result = (char *)malloc(sizeof(char) * (length + 1));
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[length] = '\0';
	return (result);
}

int	str_length(char *str)
{
	int	k;

	k = 0;
	while (str[k])
		k++;
	return (k);
}

int	str_compare(char *a, char *b)
{
	while (*a == *b)
	{
		if (*a == '\0')
			return ((unsigned char)(*a) - (unsigned char)(*b));
		a++;
		b++;
	}
	return ((unsigned char)(*a) - (unsigned char)(*b));
}

void	delete_str(char *str)
{
	free(str);
}

int	str_is_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
