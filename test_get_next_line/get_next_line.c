/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:17:39 by fgolino           #+#    #+#             */
/*   Updated: 2023/02/08 17:41:20 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*life_saver(char *str, t_bool *check, char **savior)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n' || str[i] == '\0' || str[i] == 4)
		{
			line = ft_substr(str, 0, (i + 1));
			if (str[i] == '\n')
				*check = TRUE;
			break ;
		}
		i++;
	}
	j = i;
	while (str[i])
		i++;
	if (j != i)
		*savior = copy(&(str[j + 1]), (i - j));
	return (line);
}

char	*line_parsing(char	*str, int fd, char **savior)
{
	int		i;
	char	*line;
	t_bool	check;
	char	*whatever;

	i = 0;
	check = FALSE;
	whatever = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	whatever[BUFFER_SIZE] = 0;
	line = life_saver(str, &check, savior);
	if (check == FALSE)
	{
		line = ft_strjoin(line, line_parsing(whatever, fd, savior));
	}
	free(whatever);
	return (line);
}

char	*parse_file(int fd, char **savior)
{
	char	*str;
	char	*line;

	if (*savior)
		line = line_parsing(*savior, fd, savior);
	else
	{
		str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (str == 0)
		{
			return (0);
		}
		if (!(read(fd, str, BUFFER_SIZE)))
		{
			free(str);
			return (NULL);
		}
		str[BUFFER_SIZE] = 0;
		line = line_parsing(str, fd, savior);
		free(str);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*savior;
	char		*line;
	int			i;

	i = BUFFER_SIZE;
	if (fd < 0 || i <= 0)
		return (0);
	line = parse_file(fd, &savior);
	if (line && line[0] == 0)
	{
		free(line);
		return (0);
	}
	return (line);
}
