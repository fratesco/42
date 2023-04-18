/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:01:05 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/18 18:28:29 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

void	map_freerer(char **map);
int		check_first_line(char *map_line);
int		check_border(char **map, int win, int len);
void	map_checker(char **map, int len, int win);
int		check_items(char **map, int i);
int		check_more(int exit, int coll, int start);
char	**map_parser(char *file);
void	map_displayer(char **map);
void	new_remover(char **map);
int		get_height(int fd);
int		map_size(char **map, int height);
void	invalid_item(char **map, int len, int height);
char	*input_handler(int ac, char **av);
#endif