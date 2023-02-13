/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:47:02 by fgolino           #+#    #+#             */
/*   Updated: 2023/02/13 12:37:13 by fgolino          ###   ########.fr       */
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

char	*flow_lines(char *str, int len, char **rest)
{
	int		i;
	char	*line;

	line = 0;
	i = 0;
	while (i <= len)
	{
		if ((str)[i] == '\n' || ((str)[i] == 0))
		{
			line = ft_substr(str, 0, (i + 1));
			break ;
		}
		i++;
	}
	if (*rest)
		*rest = 0;
	if (i + 1 < len)
		(*rest) = (ft_substr(str, i + 1, (len + 1)));
	return (line);
}

char	*hope_it_works(char *buffer, int len, int fd, char **rest)
{
	int		check;
	char	*line;
	char	*new_line;

	line = 0;
	new_line = 0;
	while (len)
	{
		check = check_new(buffer);
		if (check == FOUND)
		{
			new_line = flow_lines(buffer, len, rest);
			line = ft_strjoin(line, new_line);
			len = 0;
		}
		else if (check == NOTHING)
		{
			line = ft_strjoin(line, buffer);
			len = read(fd, buffer, BUFFER_SIZE);
			buffer[len] = 0;
		}
	}
	if (new_line)
		free(new_line);
	return (line);
}

char	*handler(char **rest, int fd)
{
	char	*line;
	char	*buff;
	int		len;

	line = 0;
	buff = 0;
	if (*rest)
	{
		line = flow_lines(*rest, ft_strlen(*rest), rest);
		if (check_new(line))
			return (line);
		else
		{
			buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
			len = read(fd, buff, BUFFER_SIZE);
			line = ft_strjoin(line, hope_it_works(buff, len, fd, rest));
			len = 0;
			free(buff);
		}
	}
	if (buff == 0 || (len <= 0 && buff))
		return (line);
	else
		return (0);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	int			len;
	char		*line;
	char		*buffer;

	line = 0;
	buffer = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!rest)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		len = read(fd, buffer, BUFFER_SIZE);
		buffer[len] = 0;
		if (len > 0)
			line = hope_it_works(buffer, len, fd, &rest);
		free(buffer);
	}
	else if (rest)
	{
		line = handler(&rest, fd);
	}
	return (line);
}
