/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:47:02 by fgolino           #+#    #+#             */
/*   Updated: 2023/02/08 19:12:53 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_new(char	*str)
{
	int	i;

	i = 0;
	if (!str || str[i] == 0)
		return (INVALID);
	while (str[i])
	{
		if (str[i] = '\n')
			return (FOUND);
		i++;
	}
	return (NOTHING);
}

char	*flow_lines(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if ((str)[i] == '\n' || ((str)[i] == 0))
			return (ft_substr(str, 0, (i + 1)));
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	int			len;
	char		*line;
	int			check;
	char		*buffer;

	if (fd < 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	len = read(fd, line, BUFFER_SIZE);
	if (!buffer || !len)
	{
		free(buffer);
		return (0);
	}
	while (1)
	{
		check = check_new(buffer);
		if (check == FOUND)
			line = flow_line(buffer, len);
		else if (check == NOTHING)
			
	}
	return (line);
}