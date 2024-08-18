/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:23:55 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/18 12:35:37 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	buffer;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		buffer = tab[i];
		j = i;
		while (j < size)
		{
			if (tab[j] < buffer)
			{
				buffer = tab[j];
				tab[j] = tab[i];
				tab[i] = buffer;
			}
			else
			tab[i] = buffer;
			j++;
		}
		i++;
	}
}
