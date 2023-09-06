/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:05:17 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/06 17:37:16 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_info	g_info;

int	keep_removing(char *str, int start)
{
	int		i;
	char	*tmp;

	i = start;
	tmp = 0;
	while (str && str[i])
	{
		if (str[i] == '"')
			i = remove_more(str, i, '"');
		i++;
	}
	return (i);
}

int	remove_more(char *str, int start, char needle)
{
	char	*tmp;
	int		last;
	int		i;

	last = start + 1;
	while (str && str[last])
	{
		if (str[last] == needle)
			break ;
		last++;
	}
	i = ft_strlen(str);
	tmp = strdup(&(str[last + 1]));
	ft_strlcpy(&(str[start]), &(str[start + 1]), (last));
	ft_strlcpy(&(str[last - 1]), tmp, (i));
	free(tmp);
	return (last - 2);
}
