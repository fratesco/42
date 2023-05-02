/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:01:05 by fgolino           #+#    #+#             */
/*   Updated: 2023/05/02 15:52:43 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "minilibx_opengl_20191021/mlx.h"

# define PIXELS 32

# define PLAYER "/Users/fgolino/42_git/so_long/sprites/solaire.xpm"
# define WALLS "/Users/fgolino/42_git/so_long/sprites/wall.xpm"
# define COLLECTIBLE "/Users/fgolino/42_git/so_long/sprites/estus.xpm"
# define OBSTACLE "sprites/"
# define TERRAIN "/Users/fgolino/42_git/so_long/sprites/terrain.xpm"
# define EXIT "/Users/fgolino/42_git/so_long/sprites/exit.xpm"
# define ENEMY "/Users/fgolino/42_git/so_long/sprites/enemy.xpm"
# define COLLECTIBLE2 "/Users/fgolino/42_git/so_long/sprites/estus2.xpm"
# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3
# define STILL -1
# define TAKEN 1

typedef struct s_enemy
{
	void	*sprite;
	int		num;
	int		*x;
	int		*y;
}	t_enemy;

typedef struct s_coin
{
	int		animation_step;
	int		num;
	int		max_num;
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
	int		status;
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
	void		*exit_sprite;
	t_player	*player;
	t_coin		*coins;
	t_enemy		*enemy;
}	t_game;

void	game_freerer(t_game *game, char **map);
int		check_first_line(char *map_line);
int		check_border(char **map, int win, int len);
void	map_checker(char **map, int len, int win, t_game *game);
int		check_items(char **map, int i, t_game *game, int enemy);
int		check_more(int exit, int coll, int start, t_game *game);
char	**map_parser(char *file, t_game *game);
void	initializer(t_game *game);
void	new_remover(char **map);
int		get_height(int fd);
int		map_size(char **map, int height);
void	invalid_item(char **map, int len, int height, t_game *game);
char	*input_handler(int ac, char **av);
void	get_positions(t_game *game, char **map, int exits);
void	get_coin(t_game *game, int x, int y);
void	get_player(t_game *game, int x, int y);
void	get_enemy(t_game *game, int x, int y, int enemy);
int		close_game(t_game *game);
void	reset_game(t_game *game);
int		image_handler(t_game *game);
void	load_stuff(t_game *game, int i, int j, int pix);
int		key_handler(int key, t_game *game);
void	print_game_start(t_game *game, int pix, int i, int j);
void	xpm_handler(t_game *game);
void	right_movement(t_game *game);
void	left_movement(t_game *game);
void	up_movement(t_game *game);
void	down_movement(t_game *game);
void	velocity_handler(t_game *game, int x, int y);
void	coins_handler(t_game *game, int x, int y);
void	exit_handler(t_game *game, int x, int y);
void	animation(t_game *game, t_coin *coins, int p);
#endif