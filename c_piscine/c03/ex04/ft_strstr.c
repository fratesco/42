/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 01:23:41 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/26 01:23:44 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		lt;

	i = 0;
	if (to_find[0] == 0)
		return (str = &str[0]);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = i;
			lt = 0;
			while (str[j] == to_find[lt] && to_find[lt])
			{
				lt++;
				j++;
				if (to_find[lt] == 0)
					return (str = &str[i]);
			}
		}
		i++;
	}
	return (0);
}
