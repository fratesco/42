/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:36:33 by ihhrabar          #+#    #+#             */
/*   Updated: 2022/10/30 20:36:36 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "functions.h"

char	*create_str(int lenght)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (lenght + 1));
	return (result);
}

char	*int_to_str(int n)
{
	int		i;
	char	*str;
	int		temp;

	temp = n;
	i = 0;
	while (temp != 0)
	{
		temp = temp / 10;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (str);
}
