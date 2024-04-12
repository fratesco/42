/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:29:13 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/12 19:28:30 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <error.h>
# include <string.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include "mlx_linux/mlx.h"

typedef struct s_player
{
	double	x;
	double	y;
	char	direction;
	double	direct_x;
	double	direct_y;
	int		found;
}	t_player;

typedef struct s_texture
{
	void	*ceiling;
	void	*floor;
	void	*n;
	void	*s;
	void	*w;
	void	*e;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

}	t_texture;

typedef struct s_data
{
	char		**map;
	int			map_height;
	int			ber_fd;
	char		*n_path;
	char		*s_path;
	char		*w_path;
	char		*e_path;
	int			floor_color;
	int			ceiling_color;
	int			res_h;
	int			res_w;
	void		*mlx;
	void		*window;
	int			z;
	t_list		*list;
	t_list		*save_list;
	t_player	*player;
	t_texture	*text;

}	t_data;

int		checker(t_data *data, int i, int j);
int		check_input(int argc, char **argv, t_data *data);
int		check_map(t_data *data, int i, char *tmp, int cond);
int		spaces_skipper(char *str, int start);
int		string_to_rgb(char *str, int i, int j, int counter);
int		check_lines(char *str, int start, int raw, t_data *data);
int		color_checker(char *str, int i);
int		comparer(char *tmp, t_data *data, int i);
void	free_matrix(char **matrix);
char	**matrix_crusher(char **matrix, char *str, int i);
void	freerer(t_data *data);
void	initializer(t_data *data);
int		list_free(t_data *data);
int		check_list(t_data *data, char *str, int len);
int		last_check(t_data *data, int i);
int		find_player(t_data *data, int i, int j);
void	find_direction(t_data *data);

int		nullifiereee(t_data *data);
void	keys_control_movements(int kc, t_data *data);
int		keys_control(int kc, t_data *data);
int		close_game(void);
void	print_map(t_data *data);

#endif