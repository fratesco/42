/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:15:48 by root              #+#    #+#             */
/*   Updated: 2023/01/27 16:39:01 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	loopers(char *num, int n, int i)
{
	while (((n > 0) ^ (n < 0)))
	{
		if (n < 0)
			num[i--] = n % 10 * (-1) + 48;
		else
			num[i--] = n % 10 + 48;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	char	*num;
	long	temp;

	temp = n;
	i = 0;
	while (temp && ++i)
		temp /= 10;
	if (n <= 0)
		i++;
	num = (char *)malloc(sizeof(char) * (i + 1));
	if (!num)
		return (0);
	if (n < 0)
		num[0] = '-';
	num[i--] = 0;
	if (n == 0)
		num[0] = 48;
	loopers(num, n, i);
	return (num);
}
