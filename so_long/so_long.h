/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:01:05 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/20 17:13:12 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "minilibx_opengl_20191021/mlx.h"

# define PLAYER "../sprites/solaire.xpm"
# define WALLS "../sprites/wall.xpm"
# define COLLECTIBLE "../sprites/estus.xpm"

typedef struct s_coin
{
	int	num;
	int	*x;
	int	*y;
}	t_coin;

typedef struct s_player
{
	int	start_x;
	int	start_y;
	int	x;
	int	y;
}	t_player;

typedef struct s_game
{
	char		**map;
	void		*mlx;
	void		*wind;
	int			height;
	int			lenght;
	char		*filename;
	int			exits;
	int			*exit_x;
	int			*exit_y;
	t_player	*player;
	t_coin		*coins;
}	t_game;

void	game_freerer(t_game *game);
int		check_first_line(char *map_line);
int		check_border(char **map, int win, int len);
void	map_checker(char **map, int len, int win, t_game *game);
int		check_items(char **map, int i, t_game *game);
int		check_more(int exit, int coll, int start, t_game *game);
char	**map_parser(char *file, t_game *game);
void	map_displayer(char **map);
void	new_remover(char **map);
int		get_height(int fd);
int		map_size(char **map, int height);
void	invalid_item(char **map, int len, int height, t_game *game);
char	*input_handler(int ac, char **av);
void	get_positions(t_game *game, char **map);
int		close_game(t_game *game);
#endif