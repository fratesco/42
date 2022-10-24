/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:30:14 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/24 00:55:08 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				counter;
	unsigned int	i;

	counter = 0;
	i = 0;
	while (dest[counter] != 0)
		counter++;
	while (src[i] != 0 && i < nb)
	{
		dest[counter + i] = src[i];
		i++;
	}
	dest[counter + i] = 0;
	return (dest);
}
