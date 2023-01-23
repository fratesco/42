/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:03:19 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/23 18:04:12 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*stuff;

	stuff = malloc ((count * size));
	if (stuff == 0)
		return (0);
	ft_bzero(stuff, (count * size));
	return (stuff);
}
