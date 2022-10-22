/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:50:39 by rilliano          #+#    #+#             */
/*   Updated: 2022/10/22 18:32:26 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	base_n(char *str);

int	main (int argc, char** argv)
{
	int	i;
	int n;

	n = base_n(&argv[1]);
	if (input_check(argc, argv[1], n))
	{
		write (1, "Error\n", 6);
		return (0);
	}

}
