/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:12:39 by fgolino           #+#    #+#             */
/*   Updated: 2022/11/03 17:37:38 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_doubles(int pos, char *str, char c, int flag)
{
	int i;
	i = 0;
	while (str[i] && (i < pos || flag))
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main (int argc, char **argv)
{
	int i;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	i = 0;
	while (argv[1][i])
	{
		if ((check_doubles(i, argv[1], argv[1][i])))
			write (1, &argv[1][i], 1);
		i++;
	}
	i = 0;
	while (argv[2][i])
	{
		if (check_doubles(0, argv[1], argv[2][i], 1))
		{
			if (check_doubles (i, argv[2], argv[2][i], 0))
				write (1, &argv[2][i], 1);
		}
		i++;
	}
	return (0);
}

