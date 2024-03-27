/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:29:13 by fgolino           #+#    #+#             */
/*   Updated: 2024/03/27 12:38:18 by fgolino          ###   ########.fr       */
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

typedef struct s_data
{
	char	**map;
	int		ber_fd;
	int		p_x;
	int		p_y;
	char	*n_path;
	char	*s_path;
	char	*w_path;
	char	*e_path;
	int		floor_color;
	int		ceiling_color;

}	t_data;

int		checker(t_data *data, int i, int j);
int		check_input(int argc, char **argv, t_data *data);
int		spaces_skipper(char *str, int start);
int		string_to_rgb(char *str);
int		comparer(char *tmp, t_data *data, int i);
void	free_matrix(char **matrix);
void	freerer(t_data *data);
void	initializer(t_data *data);

#endif