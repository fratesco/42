/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:03:19 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/19 18:28:52 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	void	*stuff;

	i = 0;
	stuff = malloc ((count * size));
	if (stuff == 0)
		return (0);
	ft_bzero(stuff, (count * size));
	return (stuff);
}
