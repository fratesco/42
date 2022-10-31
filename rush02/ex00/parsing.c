/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:28:05 by fbriglia          #+#    #+#             */
/*   Updated: 2022/10/30 17:28:07 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>

int	count_the_lines(char *str)
{
	int	result;

	result = 1;
	while (*str)
	{
		if (*str == '\n')
			result++;
		str++;
	}
	return (result);
}

char	*make_string(char *str, int start, int end)
{
	int		i;
	int		length;
	char	*result;

	length = end - start;
	result = (char *)malloc(sizeof(char) * (length + 1));
	i = 0;
	while (i < length)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	parse_line(char *dict_str, int line_pos, t_dict *dict)
{
	int		start;
	int		i;
	char	*num_str;
	char	*name_str;

	start = line_pos;
	i = line_pos;
	while (dict_str[i] >= '0' && dict_str[i] <= '9')
		i++;
	num_str = make_string(dict_str, start, i);
	while (dict_str[i] == ' ')
		i++;
	dict->max_length -= (dict->max_length + 1) * (dict_str[i++] != ':');
	while (dict_str[i] == ' ')
		i++;
	start = i;
	while (dict_str[i] != '\n' && (dict_str[i] >= 32 && dict_str[i] <= 126))
		i++;
	name_str = make_string(dict_str, start, i);
	if (*num_str == '\0' || *name_str == '\0')
		dict->max_length = -1;
	dict_set_value(dict, num_str, name_str);
	delete_str(num_str);
	delete_str(name_str);
}

t_dict	parse_number_naming_dictionary(char *dict_str)
{
	t_dict	result;
	int		line_pos;
	int		i;

	line_pos = 0;
	i = 0;
	result = new_dict(count_the_lines(dict_str));
	while (dict_str[i])
	{
		if (dict_str[i] == '\n')
		{
			if (dict_str[i - 1] != '\n')
				parse_line(dict_str, line_pos, &result);
			line_pos = i + 1;
		}
		i++;
	}
	if (dict_str[i - 1] != '\n')
		parse_line(dict_str, line_pos, &result);
	return (result);
}
