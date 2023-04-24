/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:12:17 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/24 18:04:16 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	game_freerer(game);
	exit(0);
}

void	reset_game(t_game *game)
{
	get_positions(game, game->map);
	game->game_iteration = 0;
	game->frame = 0;
}

void	exit_handler(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->exits)
	{
		ft_printf("cazzi");
		if (x == game->exit_x[i] && y == game->exit_y[i])
		{
			game_freerer(game);
			exit(0);
		}
		i++;
	}
}

char	*input_handler(int ac, char **av)
{
	int	i;

	if (ac < 2)
	{
		ft_printf("Too few arguments\n");
		exit (0);
	}
	if (ac > 2)
	{
		ft_printf("Too many arguments\n");
		exit (0);
	}
	i = ft_strlen(av[1]);
	if ((i >= 4) && (av[1][i - 1] == 'r') && (av[1][i - 2] == 'e')
		&& (av[1][i - 3] == 'b') && (av[1][i - 4] == '.'))
		return (av[1]);
	else
	{
		ft_printf("Not a '.ber' file");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_coin		coins;
	t_player	player;

	game.game_iteration = 0;
	game.coins = &coins;
	game.player = &player;
	game.coins->num = 0;
	game.coins->max_num = 0;
	game.coins->flag = 0;
	game.exits = 0;
	game.moves = 0;
	game.frame = 0;
	game.filename = input_handler(argc, argv);
	game.map = map_parser(game.filename, &game);
	game.mlx = mlx_init();
	game.wind = mlx_new_window(game.mlx, (game.lenght * 32),
			(game.height * 32) + 32, "so_long");
	mlx_hook(game.wind, 17, 0, close_game, (&game));
	mlx_loop_hook(game.mlx, image_handler, &game);
	mlx_key_hook(game.wind, key_handler, &game);
	mlx_loop(game.mlx);
	game_freerer(&game);
	return (0);
}
