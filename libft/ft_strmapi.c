/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:42:12 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/23 18:12:22 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (s == 0)
		return (0);
	i = ft_strlen(s);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str[i--] = 0;
	while (i >= 0)
	{
		str[i] = f(i,s[i]);
		i--;
	}
	return (str);
}
 