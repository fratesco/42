/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:47:18 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/24 17:13:16 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int letter)
{
	if (letter >= 65 && letter <= 90)
		return (1);
	else if (letter >= 97 && letter <= 122)
		return (1);
	else
		return (0);
}
