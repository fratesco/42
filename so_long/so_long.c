/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:12:17 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/18 18:30:14 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*input_handler(int ac, char **av)
{
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
	return (av[1]);
}

int	main(int argc, char **argv)
{
	char	**map;
	char	*filename;

	filename = input_handler(argc, argv);
	map = map_parser(filename);
	map_freerer(map);
	return (0);
}
