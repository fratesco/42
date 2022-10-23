/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.C                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:07:33 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/24 00:43:04 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char b)
{
	int		dec;
	int		f;
	char	*a;

	a = "0123456789abcdef";
	dec = b;
	write(1, "\\", 1);
	f = dec / 16;
	write(1, &a[f], 1);
	f = dec % 16;
	write(1, &a[f], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	c;

	c = 0;
	while (str[c] != 0)
	{
		if (str[c] >= 33 && str[c] <= 126)
			write(1, &str[c], 1);
		else if (str[c] < 32 && str[c] > 126)
			print_hex(str[c]);
		c++;
	}
}
