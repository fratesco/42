/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:29:35 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/20 18:09:54 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	front_check(char const *s1, char const *set)
{
	int	x;
	int	i;
	int	counter;

	x = 0;
	counter = 0;
	i = 0;
	while (set[i])
	{
		if (set[i] == s1[x])
		{
			i = 0;
			x++;
			counter++;
			continue ;
		}
		i++;
	}
	return (counter);
}

int	back_check(char const *s1, char const *set)
{
	int	x;
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	x = ft_strlen(s1) - 1;
	while (set[i])
	{
		if (set[i] == s1[x])
		{
			i = 0;
			x--;
			counter++;
			continue ;
		}
		i++;
	}
	return (counter);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*str;

	i = ft_strlen(s1) - (front_check(s1, set) + back_check(s1, set)) + 1;
	str = (char *)malloc(i * sizeof(char));
	return (str);
}
