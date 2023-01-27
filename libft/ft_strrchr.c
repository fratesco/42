/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:57:48 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/24 16:34:27 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int		i;
	char	*last;

	i = 0;
	last = 0;
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
