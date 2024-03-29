/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:02:40 by fgolino           #+#    #+#             */
/*   Updated: 2023/05/09 17:53:24 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**map_parser(char *file, t_game *game)
{
	char	**map;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	game->height = get_height(fd);
	close(fd);
	map = (char **)malloc((game->height + 1) * sizeof(char *));
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < game->height)
		map[i++] = get_next_line(fd);
	map[i] = 0;
	close(fd);
	game->lenght = ft_strlen(map[0]) - 1;
	map_checker(map, game->lenght, game->height, game);
	get_positions(game, map, 0);
	return (map);
}

void	map_checker(char **map, int len, int height, t_game *game)
{
	int	i;

	i = -1;
	new_remover(map);
	if (len < 3 || height < 3 || map_size(map, height - 1) || len + height < 8)
	{
		ft_printf("Error\nInvadlid Map Size\n");
		game_freerer(game, map);
		exit(0);
	}
	invalid_item(map, len, height - 1, game);
	if (check_first_line(map[0]) || check_first_line(map[height - 1])
		|| check_border(map, height - 1, len))
	{
		ft_printf("Error\nMap not surrounded by walls\n");
		game_freerer(game, map);
		exit(0);
	}
	if (check_items(map, i, game, 0))
	{
		ft_printf("Error\nA key component is missing or too many spawns\n");
		game_freerer(game, map);
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

void	game_freerer(t_game *game, char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map[i]);
	free(map);
	if (game->coins->x)
		free(game->coins->x);
	if (game->coins->y)
		free(game->coins->y);
	if (game->exit_x)
		free(game->exit_x);
	if (game->exit_y)
		free(game->exit_y);
	if (game->enemy->x)
		free(game->enemy->x);
	if (game->enemy->y)
		free(game->enemy->y);
	image_destroyer(game);
}
