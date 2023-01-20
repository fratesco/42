/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:57:48 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/19 18:24:28 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	int		i;
	char	*last = 0;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			last = &(str[i]);
		i++;
	}
	if (c == 0)
		return (&(str[i]));
	return (last);
}
