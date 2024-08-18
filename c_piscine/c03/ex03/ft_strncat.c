/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 01:22:42 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/26 01:22:44 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	ls;

	i = 0;
	ls = 0;
	while (dest[i] != 0)
		i++;
	while (src[ls] != 0 && ls < nb)
	{
		dest[i] = src[ls];
		ls++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}
