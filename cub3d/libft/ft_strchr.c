/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:46:33 by fgolino           #+#    #+#             */
/*   Updated: 2024/03/26 17:33:03 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == (char)c)
			return (&(str[i]));
		i++;
	}
	if (c == 0)
		return (&(str[i]));
	return (0);
}
