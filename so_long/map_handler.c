/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:02:40 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/14 09:48:49 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_parser(char *file)
{
	char	**map;
	int		fd;
	int		len;
	int		win;
	int		i;

	win = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd))
		win++;
	close(file);
	map = (char **)malloc((win + 1) * sizeof(char *));
	fd = open(file, O_RDONLY);
	i = 0;
	while (win-- > 0)
		map[i++] = get_next_line(fd);
	map [i] = 0;
	close(fd);
	len = ft_strlen(map[0]);
	map_checker(map, len, win);
	return (map);
}

void	map_checker(char **map, int len, int win)
{
	
}

void	map_freerer(char **map)
{
	int	i;

	while (map[i])
		free(map[i++]);
	free(map[i]);
	free(map);
}
