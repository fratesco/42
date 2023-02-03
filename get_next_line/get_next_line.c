/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:17:39 by fgolino           #+#    #+#             */
/*   Updated: 2023/02/03 15:22:11 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_parsing(char	*str, int fd)
{
	static size_t	i;
	char			*line;
	t_bool			check;

	i = 0;
	check = FALSE;
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n')
		{
			line = ft_substr(str, 0, (i + 1));
			check == TRUE;
		}
	}
	if (check == FALSE)
	{
		line = ft_strjoin(line, line_parsing(read(fd, line, BUFFER_SIZE), fd));
	}
	return (line);
}

char	*parse_file(int fd)
{
	char	*str;
	char	*line;

	line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	str = read(fd, str, BUFFER_SIZE);
	line = line_parsing(str,fd);
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	line = parse_file(fd);
	return (line);
}
