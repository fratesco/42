/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:41:41 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/24 17:37:36 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = ft_strlen(str) + 1;
	while (i--)
	{
		if (*str == (char) c)
			return ((char *) str);
		str++;
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, int n)
{
	int		i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (n >= 0)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
		n--;
	}
	return ((void *)dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	free(s1);
	return (str);
}

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
