/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:12:17 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/19 15:39:22 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	game.coins = &coins;
	game.coins->num = 0;
	game.player = &player;
	game.filename = input_handler(argc, argv);
	game.map = map_parser(game.filename, &game);
	game.mlx = mlx_init();
	game.wind = mlx_new_window(game.mlx, game.lenght * 32, game.height * 32, "so_long");
	game_freerer(&game);
	return (0);
}
