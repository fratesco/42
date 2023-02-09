/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:47:02 by fgolino           #+#    #+#             */
/*   Updated: 2023/02/09 11:58:48 by fgolino          ###   ########.fr       */
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
		if (str[i] == '\n')
			return (FOUND);
		i++;
	}
	return (NOTHING);
}

char	*flow_lines(char *str, int len, char *rest)
{
	int		i;
	char	*line;

	i = 0;
	while (i <= len)
	{
		if ((str)[i] == '\n' || ((str)[i] == 0))
		{
			line = ft_substr(str, 0, (i + 1));
			break ;
		}
	}
	if (i != len)
		rest = (ft_substr(str, i, (len + 1)));
	return (0);
}

char	*hope_it_works(char *buffer, int len, int fd, char *rest)
{
	int		check;
	char	*line;

	while (len)
	{
		check = check_new(buffer);
		if (check == FOUND)
		{
			line = flow_lines(buffer, len, rest);
			break ;
		}
		else if (check == NOTHING)
		{
			line = ft_strjoin(line, buffer);
			len = read(fd, buffer, BUFFER_SIZE);
			buffer[BUFFER_SIZE] = 0;
		}
	}
	return (line);
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
	buffer[BUFFER_SIZE] = 0;
	if (!buffer || !len)
	{
		free(buffer);
		return (0);
	}
	if (rest)
	{
		line = flow_lines(rest, ft_strlen(rest), rest);
		free(rest);
	}
	line = hope_it_works(buffer, len, fd, rest);
	free(buffer);
	return (line);
}