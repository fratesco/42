/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:54:21 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/24 00:47:59 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (src[i] == 0 && i != n)
		{
			while (i < n)
			{
				dest[i] = 0;
				i++;
			}
		}
		else
		{
			dest[i] = src[i];
			i++;
		}
	}
	if (src[i] == 0)
		dest[i] = 0;
	return (dest);
}
