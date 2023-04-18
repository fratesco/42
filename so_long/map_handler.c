/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:02:40 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/18 18:13:18 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_parser(char *file)
{
	char	**map;
	int		fd;
	int		len;
	int		height;
	int		i;

	fd = open(file, O_RDONLY);
	height = get_height(fd);
	close(fd);
	map = (char **)malloc((height + 1) * sizeof(char *));
	fd = open(file, O_RDONLY);
	i = 0;
	height--;
	while (i <= height)
		map[i++] = get_next_line(fd);
	map[i] = 0;
	close(fd);
	len = ft_strlen(map[0]) - 1;
	map_checker(map, len, height);
	return (map);
}

void	map_checker(char **map, int len, int height)
{
	int	i;

	i = 0;
	new_remover(map);
	map_displayer(map);
	if (len < 4 || map_size(map, height))
	{
		ft_printf("Error\nInvadlid Map Size\n");
		map_freerer(map);
		exit(0);
	}
	invalid_item(map, len, height);
	if (check_first_line(map[0]) || check_first_line(map[height])
		|| check_border(map, height, len))
	{
		ft_printf("Error\nMap not surrounded by walls\n");
		map_freerer(map);
		exit(0);
	}
	if (check_items(map, i))
	{
		ft_printf("Error\nA key component is missing\n");
		map_freerer(map);
		exit(0);
	}
}

int	check_border(char **map, int height, int len)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		if (map[(i)][0] != '1' || map[(i)][len - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_first_line(char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i++] != '1')
			return (1);
	}
	return (0);
}

void	map_freerer(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map[i]);
	free(map);
}
