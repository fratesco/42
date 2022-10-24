/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:17:41 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/24 00:53:32 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char	*dest, char	*src)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (dest[counter] != 0)
		counter++;
	while (src[i] != 0)
	{
		dest[counter + i] = src[i];
		i++;
	}
	dest[counter + i] = 0;
	return (dest);
}
