/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringmath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:36:20 by ihhrabar          #+#    #+#             */
/*   Updated: 2022/10/30 20:36:23 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>
#include <unistd.h>

void	remove_zeroes(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == '0' && str[i + 1] != '\0')
		i++;
	while (str[i] != '\0')
	{
		str[j] = str[i];
		i++;
		j++;
	}
	while (str[j] != '\0')
	{
		str[j] = '\0';
		j++;
	}
}

void	sub_helper(char *a, char *b, char *r, char diff)
{
	int		i;
	int		remainder;

	i = 0;
	remainder = 0;
	while (++i <= str_length(b))
	{
		diff = a[str_length(a) - i] - b[str_length(b) - i];
		diff -= remainder;
		remainder = 0;
		if (diff < 0)
		{
			remainder = 1;
			diff += 10;
		}
		r[str_length(a) - i] = '0' + diff;
	}
	while (i <= str_length(a))
	{
		r[str_length(a) - i] = a[str_length(a) - i] - (1 * remainder);
		remainder = r[str_length(a) - i] < '0';
		r[str_length(a) - i] += 10 * (r[str_length(a) - i] < '0');
		i++;
	}
}

char	*sub_num_str(char *a, char *b)
{
	char	*result;

	result = new_str(a);
	sub_helper(a, b, result, 0);
	remove_zeroes(result);
	return (result);
}

int	equal_num_str(char *a, char *b)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	i = str_length(a);
	k = str_length(b);
	if (i != k)
		return (0);
	i--;
	k--;
	while (a[i] && b[k])
	{
		if (a[i] == b[k])
		{
			i--;
			k--;
		}
		else
			return (0);
	}
	return (1);
}

int	larger_num_str(char *a, char *b)
{
	int	i;

	if (str_length(a) > str_length(b))
		return (1);
	if (str_length(a) < str_length(b))
		return (0);
	i = 0;
	while (a[i] && b[i])
	{
		if (a[i] != b[i])
			return (a[i] > b[i]);
		i++;
	}
	return (0);
}
