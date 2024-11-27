/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 05:37:14 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/31 17:59:59 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	n;

	n = 1;
	if (n < 0)
		return (0);
	while (n <= nb / n)
	{
		if ((n * n) == nb)
			return (n);
		n++;
	}
	return (0);
}