/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:15:48 by root              #+#    #+#             */
/*   Updated: 2023/01/21 14:42:14 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	*num;
	long	temp;

	temp = n;
	while (temp)
	{
		temp /= 10;
		i++;
	}
	if (n < 0)
		i++;
	num = (char *)malloc(sizeof(char) * (i + 1));
	if (n < 0)
		num[0] = '-';
	num[i--] = 0;
	while (n >= 0 ^ n < 0)
	{
		if (n < 0)
			num[i] = n % 10 * (-1);
		else
			num[i] = n % 10;
		i--;
	}
	return (num);
}
