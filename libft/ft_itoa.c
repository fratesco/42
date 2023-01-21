/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:15:48 by root              #+#    #+#             */
/*   Updated: 2023/01/21 23:53:00 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (n < 0)
		num[0] = '-';
	num[i--] = 0;
	if (n == 0)
		num[0] == 48;
	while (n > 0 ^ n < 0)
	{
		if (n < 0)
			num[i--] = n % 10 * (-1) + 48;
		else
			num[i--] = n % 10 + 48;
		n /= 10;
	}
	return (num);
}
