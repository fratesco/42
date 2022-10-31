/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:51:18 by ihhrabar          #+#    #+#             */
/*   Updated: 2022/10/29 17:51:20 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>

t_dict	new_dict(int max_length)
{
	t_dict	result;

	result.length = 0;
	result.max_length = max_length;
	result.keys = (char **)malloc(sizeof(char *) * max_length);
	result.values = (char **)malloc(sizeof(char *) * max_length);
	return (result);
}

//print_str("NONE_VALUE");
char	*dict_get_value(t_dict *d, char *key)
{
	int	i;

	i = 0;
	while (i < d->length)
	{
		if (str_compare(key, d->keys[i]) == 0)
		{
			return (d->values[i]);
		}
		i++;
	}
	return (NONE_VALUE);
}

//print_str("KEY_ALREADY_EXISTS");
//print_str("MAX_CAPACITY_REACHED");
int	dict_set_value(t_dict *d, char *key, char *value)
{
	int	i;

	i = 0;
	while (i < d->length)
	{
		if (str_compare(key, d->keys[i]) == 0)
		{
			return (KEY_ALREADY_EXISTS);
		}
		i++;
	}
	if (i >= d->max_length)
	{
		return (MAX_CAPACITY_REACHED);
	}
	d->length = i + 1;
	d->keys[i] = new_str(key);
	d->values[i] = new_str(value);
	return (1);
}

void	delete_dict(t_dict *d)
{
	int	i;

	i = 0;
	while (i < d->length)
	{
		delete_str(d->keys[i]);
		delete_str(d->values[i]);
		i++;
	}
	d->length = 0;
	d->max_length = 0;
}
