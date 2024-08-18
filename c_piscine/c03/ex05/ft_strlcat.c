/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 01:23:19 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/26 01:23:20 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	ls;
	unsigned int	rvalue;

	ls = 0;
	i = 0;
	while (src[ls])
		ls++;
	while (dest[i])
		i++;
	if (size < 1)
		return (ls);
	if (size < ls)
		rvalue = ls + size;
	else
		rvalue = i + ls;
	ls = 0;
	size -= i;
	while (src[ls] && ls < size - 1)
	{
		dest[i + ls] = src[ls];
		ls++;
	}
	dest[i + ls] = 0;
	return (rvalue);
}
