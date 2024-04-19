/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:29:13 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/19 13:35:19 by fgolino          ###   ########.fr       */
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

# define X 0
# define Y 1

typedef struct s_player
{
	double	x;
	double	y;
	int		map_x;
	int		map_y;
	char	direction;
	double	camera_x;
	double	camera_y;
	int		found;
	int		space;
}	t_player;

typedef struct s_ray
{
	double	direct_x;
	double	direct_y;
	double	plane_x;
	double	plane_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_x;
	double	delta_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
}	t_ray;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		color;
	int		w;
	int		h;
	char	*path;

}	t_texture;

typedef struct s_data
{
	char		**map;
	int			map_height;
	int			ber_fd;
	int			floor_color;
	int			ceiling_color;
	int			res_h;
	int			res_w;
	void		*mlx;
	void		*window;
	int			z;
	int			hit;
	int			side;
	t_list		*list;
	t_list		*save_list;
	t_player	*player;
	t_texture	ceiling;
	t_texture	floor;
	t_texture	n;
	t_texture	s;
	t_texture	w;
	t_texture	e;
	t_texture	image;
	t_texture	minimap;
	t_ray		ray;

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
void	initialize_texture(t_data *data);
int		list_free(t_data *data);
int		check_list(t_data *data, char *str, int len);
int		last_check(t_data *data, int i);
int		find_player(t_data *data, int i, int j);
void	find_direction(t_data *data);
int		check_text_path(t_data *data);
void	image_destroyer(t_data *data, void *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_images(t_data *data);
void	raycasting(t_data *data);
void	calcs(t_data *data);
void	get_step(t_data *data);

int		nullifiereee(t_data *data);
void	keys_control_movements(int kc, t_data *data);
int		keys_control(int kc, t_data *data);
int		close_game(void);
void	print_map(t_data *data);
void	mlx_handler(t_data *data);

#endif