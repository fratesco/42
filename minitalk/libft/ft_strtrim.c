/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:29:35 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/27 15:32:48 by fgolino          ###   ########.fr       */
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
	while (set[i] && x >= 0)
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
	int		back;
	int		front;
	int		len;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	back = back_check(s1, set);
	front = front_check(s1, set);
	if (len == 0 || (len == back && back == front))
		return (ft_strdup(""));
	str = (char *)malloc((len - back - front + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while ((i + front + back <= len))
		i++;
	ft_strlcpy(str, &(s1[front]), i);
	return (str);
}
