/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:17:39 by fgolino           #+#    #+#             */
/*   Updated: 2023/02/07 18:42:24 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*life_saver(char	*str, t_bool *check, int i, char **savior)
{
	char	*line;

	if (*savior)
	{
		line = (*savior);
		*savior = 0;
		return (line);
	}
	else if (str)
	{
		line = ft_substr(str, 0, (i + 1));
		*savior = ft_substr(str, i, (ft_strlen(str) - i + 1));
		*check = TRUE;
		return (line);
	}
	return (0);
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
	if (savior && *savior)
		line = life_saver(0, &check, ft_strlen(*savior), savior);
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n' || str[i] == '\0' || str[i] == 4)
			line = life_saver(str, &check, i, savior);   //PROBLEMA QUI!
		i++;
	}
	if (check == FALSE)
	{
		read(fd, whatever, BUFFER_SIZE);
		line = ft_strjoin(str, line_parsing(whatever, fd, savior));
	}
	free(whatever);
	return (line);
}

char	*parse_file(int fd, char **savior)
{
	char	*str;
	char	*line;

	str = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (str == 0)
	{
		return (0);
	}
	if (!(read(fd, str, BUFFER_SIZE)))
	{
		free(str);
		return (NULL);
	}
	line = line_parsing(str, fd, savior);
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			i;
	static char	*savior;

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
