/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:39:18 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/25 14:49:36 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_loop(char *str, char *to_find, int size)
{
	int	k;

	k = 0;
	while (str[k] == to_find[k])
		k++;
	if (k == size)
		return (1);
	return (0);
}

char	*resemblance_checker(char *str, char *to_find, int size)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == to_find[0])
		{
			if ((check_loop(&str[i], to_find, size) == 1))
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_strstr(char	*str, char	*to_find)
{
	int	counter1;
	int	size;

	counter1 = 0;
	size = 0;
	while (to_find[size] != 0)
		size++;
	if (size == 0)
		return (str);
	return (resemblance_checker(str, to_find, size));
}
