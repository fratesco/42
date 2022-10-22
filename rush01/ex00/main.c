/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:50:39 by rilliano          #+#    #+#             */
/*   Updated: 2022/10/22 18:01:57 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	base_n(char *str);

int	main (int argc, char** argv)
{
	int	i;
	int n;

	n = base_n(&argv[1]);
	if (input_check(&str[1]))
		return (0);

	while (i < (n * n * 2 - 1)
	{
		if (argv[1][i] == ' ')
		{

			i = i + 2;
		else
		{
			write (1, "Error\n", 6);
			return ;
		}
	}

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] > '0' || argv[1][i] < '5')
			i = i + 2;
		else
		{
			write (1, "Error\n", 6);
			return ;
		}
	}

}
