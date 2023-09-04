/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:05:17 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/04 17:44:47 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_info	g_info;

char	*keep_removing(char *str, int stop, char needle)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = 0;
	while (str && str[i] && i < stop)
	{
		if (str[i] == needle)
			return (quote_remover(str, needle, stop));
		i++;
	}
	while (str && str[i])
	{
		if (str[i] == '"')
			tmp = quote_remover(&str[stop - 1], '"', -1);
		else if (str[i] == '\'')
			tmp = quote_remover(&str[stop - 1], '\'', -1);
		i++;
	}
	if (tmp)
	{
		ft_strlcpy(&str[stop - 1], tmp, ft_strlen(tmp) + 1);
		//free(tmp);
	}
	return (str);
}
