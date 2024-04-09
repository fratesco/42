/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:41:46 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/09 18:15:45 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_brokenl(char *brokenl)
{
	char	*newbl;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (brokenl[i] && brokenl[i] != '\n')
		i++;
	if (!brokenl[i] || (!brokenl[i + 1] && brokenl[i] == '\n'))
	{
		free (brokenl);
		return ((void *)1);
	}
	newbl = (char *)malloc(sizeof(char) * (ft_strlen(brokenl) - i + 1));
	if (!newbl)
	{
		free(newbl);
		return (NULL);
	}
	while (brokenl[i])
		newbl[j++] = brokenl[1 + i++];
	newbl[j] = 0;
	free(brokenl);
	return (newbl);
}

char	*get_fixed_line(const char *brokenl)
{
	char	*fixedl;
	int		i;
	int		x;

	i = 0;
	if (!brokenl[0])
		return (NULL);
	while (brokenl[i] && brokenl[i] != '\n')
		i++;
	fixedl = (char *)malloc(sizeof(char) * (i + 1));
	if (!fixedl)
	{
		free (fixedl);
		return (NULL);
	}
	x = 0;
	while (i--)
	{
		fixedl[x] = brokenl[x];
		x++;
	}
	fixedl[x] = 0;
	return (fixedl);
}

char	*get_broken_line(int fd, char *brokenl, int rlen)
{
	char	*buf;
	char	*tmp;

	if (brokenl == (void *)1)
		return (brokenl);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return ((void *)1);
	while (rlen != 0 && ft_strchr(brokenl, '\n') == 0)
	{
		rlen = read(fd, buf, BUFFER_SIZE);
		if (rlen == -1)
		{
			free (buf);
			return ((void *)1);
		}
		buf[rlen] = 0;
		tmp = ft_strjoin(brokenl, buf);
		if (brokenl)
			free(brokenl);
		brokenl = tmp;
	}
	free (buf);
	return (brokenl);
}

char	*get_next_line(int fd)
{
	char		*fixedl;
	static char	*brokenl;

	if (fd == -1 && brokenl)
	{
		if (brokenl != (void *)1)
			free(brokenl);
		return (NULL);
	}
	else if (fd < 0 || BUFFER_SIZE < 1)
		return ((void *)1);
	brokenl = get_broken_line(fd, brokenl, 1);
	if (brokenl == (void *)1)
		return (brokenl);
	else if (!brokenl)
		return (NULL);
	fixedl = get_fixed_line(brokenl);
	brokenl = get_next_brokenl(brokenl);
	return (fixedl);
}

// int	main()
// {
// 	int fd = open("loreipsum.txt", O_RDONLY);
// 	char *s = get_next_line(fd);

// 	while (s)
// 	{
// 		printf("%s", s);
// 		s = get_next_line(fd);
// 	}
// 	close(fd);
// 	check_leaks();
// 	return (0);
// }
