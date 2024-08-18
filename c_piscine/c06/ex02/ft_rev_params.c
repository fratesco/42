/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 07:26:28 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/24 07:30:55 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	if (argc < 2)
		return (0);
	while (argc - j > 0)
	{
		i = 0;
		while (argv[argc - j][i] != 0)
		{
			write(1, &argv[argc - j][i], 1);
			i++;
		}
		write (1, "\n", 1);
		j++;
	}
}
