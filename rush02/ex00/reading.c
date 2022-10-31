/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:29:35 by fbriglia          #+#    #+#             */
/*   Updated: 2022/10/30 16:29:41 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "functions.h"
#include <stdlib.h>

#define READING_STEP 100

int	file_size(int descriptor)
{
	int		i;
	char	buf[READING_STEP];
	int		result;

	i = read(descriptor, buf, READING_STEP);
	result = 0;
	while (i == READING_STEP)
	{
		result += i;
		i = read(descriptor, buf, READING_STEP);
	}
	result += i;
	close(descriptor);
	return (result);
}

char	*read_number_naming_dictionary(char *dict_path)
{
	int		descriptor;
	char	*result;
	int		length;

	descriptor = open(dict_path, O_RDONLY);
	if (descriptor < 0)
		return (0);
	length = file_size(descriptor);
	close(descriptor);
	result = (char *)malloc(sizeof(char) * (length + 1));
	descriptor = open(dict_path, O_RDONLY);
	read(descriptor, result, length);
	close(descriptor);
	result[length] = '\0';
	return (result);
}
