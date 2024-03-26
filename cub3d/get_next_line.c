/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:41:46 by fgolino           #+#    #+#             */
/*   Updated: 2024/03/26 17:42:34 by fgolino          ###   ########.fr       */
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
	while (brokenl[i] && brokenl[i - 1] != '\n')
		i++;
	if (!brokenl[i])
	{
		free (brokenl);
		return (NULL);
	}
	newbl = (char *)malloc(sizeof(char) * (ft_strlen(brokenl) - i + 1));
	if (!newbl)
		return (NULL);
	while (brokenl[i])
		newbl[j++] = brokenl[i++];
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
	while (brokenl[i] && brokenl[i - 1] != '\n')
		i++;
	fixedl = (char *)malloc(sizeof(char) * (i + 1));
	if (!fixedl)
		return (NULL);
	x = 0;
	while (i--)
	{
		fixedl[x] = brokenl[x];
		x++;
	}
	fixedl[x] = 0;
	return (fixedl);
}

char	*get_broken_line(int fd, char *brokenl)
{
	int		rlen;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	rlen = 1;
	while (rlen != 0 && ft_strchr(brokenl, '\n') == 0)
	{
		rlen = read(fd, buf, BUFFER_SIZE);
		if (rlen == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[rlen] = 0;
		brokenl = ft_strjoin(brokenl, buf);
	}
	free (buf);
	return (brokenl);
}

char	*get_next_line(int fd)
{
	char		*fixedl;
	static char	*brokenl;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	brokenl = get_broken_line(fd, brokenl);
	if (!brokenl)
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
