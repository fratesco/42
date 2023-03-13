/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:14:44 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/13 08:42:29 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instructions	*new(char *instruction)
{
	t_instructions	*list;
	size_t			len;
	int				i;

	i = 0;
	list = (t_instructions *)malloc(sizeof(t_instructions));
	len = ft_strlen(instruction);
	list->command = (char *)malloc(sizeof(char) * len + 1);
	while (i <= len)
	{
		(list->command)[i] = instruction[i];
		i++;
	}
	list->next = 0;
	return (list);
}

void	add_back(t_instructions **list, t_instructions *new)
{
	while (*list)
	{
		if ((*list)->next == 0)
		{
			(*list)->next = new;
			return ;
		}
		list = &(*list)->next;
	}
}

void	add_instruction(t_instructions **list, char *instruction)
{
	t_instructions	*node;

	node = new(instruction);
	add_back(list, node);
}

void	clear_node(t_instructions **list)
{
	t_instructions	*tmp;

	tmp = (*list);
	(*list) = (*list)->next;
	free((tmp)->command);
	free(tmp);
}
