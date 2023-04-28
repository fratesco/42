/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:46:14 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/28 17:27:13 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_items(char **map, int i, t_game *game, int enemy)
{
	int	j;
	int	exit;
	int	coll;
	int	start;

	exit = 0;
	coll = 0;
	start = 0;
	while (map && map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				coll++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'P')
				start++;
			else if (map[i][j] == 'N')
				enemy++;
		}
	}
	get_enemy(game, -1, -1, enemy);
	return (check_more(exit, coll, start, game));
}

int	check_more(int exit, int coll, int start, t_game *game)
{
	game->coins->x = (int *)malloc(coll * sizeof(int));
	game->coins->y = (int *)malloc(coll * sizeof(int));
	game->exit_x = (int *)malloc(exit * sizeof(int));
	game->exit_y = (int *)malloc(exit * sizeof(int));
	if (exit == 0 || coll == 0 || start == 0)
		return (1);
	if (start > 1)
		return (1);
	return (0);
}

void	initializer(t_game *game)
{
	game->exit_x = 0;
	game->exit_y = 0;
	game->coins->x = 0;
	game->coins->y = 0;
	game->coins->num = 0;
	game->coins->max_num = 0;
	game->coins->flag = 0;
	game->exits = 0;
	game->moves = 0;
	game->frame = 0;
	game->enemy->num = 0;
	game->enemy->x = 0;
	game->enemy->y = 0;
	game->player->status = 0;
}

void	new_remover(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				map[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	get_height(int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp)
		{
			free(tmp);
			i++;
		}
		else
			return (i);
	}
	return (i);
}
