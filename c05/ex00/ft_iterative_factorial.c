/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 04:39:42 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/24 04:48:31 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	fact;

	i = 0;
	fact = nb;
	if (nb < 0)
		return (0);
	while (i < nb - 1)
	{
		fact *= nb - 1 - i;
		i++;
	}
	return (fact);
}
