/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:03:31 by fgolino           #+#    #+#             */
/*   Updated: 2022/11/03 16:13:37 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*str_cpy(char *str)
{
	int		i;
	int		size;
	char	*strcpy;

	i = 0;
	size = str_len(str);
	strcpy = (char *)malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		strcpy[i] = str[i];
		i++;
	}
	strcpy[i] = 0;
	return (strcpy);
}

void	struct_insert(char *str, struct s_stock_str *strukt, int flag)
{
	strukt->size = str_len(str);
	strukt->copy = str_cpy(str);
	if (flag == 1)
		strukt->str = 0;
	else
		strukt->str = str;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*stock;

	if (ac < 2)
		return (NULL);
	stock = (struct s_stock_str)malloc(sizeof(struct s_stock_str) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		struct_insert(av[i], stock[i], 0);
		i++;
	}
	stock[i].str = 0;
	stock[i].copy = 0;
	return (stock);
}
