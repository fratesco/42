/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:03:25 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/27 15:57:34 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	else
	{
		tmp = lst;
		lst = tmp->next;
		del(tmp->content);
		free(tmp);
	}
}
