/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:01:05 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/23 17:45:11 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "minilibx_opengl_20191021/mlx.h"

# define PIXELS 32

# define PLAYER "solaire.xpm"
# define WALLS "wall.xpm"
# define COLLECTIBLE "estus.xpm"
# define OBSTACLE "sprites/"
# define TERRAIN "terrain.xpm"
# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3
# define STILL -1
# define TAKEN 1

typedef struct s_coin
{
	int		animation_step;
	int		num;
	int		*x;
	int		*y;
	int		flag;
	void	*sprite[4];
}	t_coin;

typedef struct s_player
{
	int		start_x;
	int		start_y;
	int		x;
	int		y;
	int		velocity;
	void	*sprite;
}	t_player;

typedef struct s_game
{
	int			game_iteration;
	int			frame;
	char		**map;
	void		*mlx;
	void		*wind;
	int			height;
	int			lenght;
	char		*filename;
	int			exits;
	int			*exit_x;
	int			*exit_y;
	int			moves;
	void		*walls_sprite;
	void		*terrain_sprite;
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
void	get_coin(t_game *game, int x, int y);
void	get_player(t_game *game, int x, int y);
int		close_game(t_game *game);
void	reset_game(t_game *game);
int		image_handler(t_game *game);
int		key_handler(int key, t_game *game);
void	print_game_start(t_game *game, int pix, int i, int j);
void	xpm_handler(t_game *game);
void	right_movement(t_game *game);
void	left_movement(t_game *game);
void	up_movement(t_game *game);
void	down_movement(t_game *game);
#endif