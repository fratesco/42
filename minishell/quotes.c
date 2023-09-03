/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:02:58 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/03 13:18:11 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_info	g_info;

void	single_quotes(char *str, int *num_single, int *i)
{
	(*num_single)++;
	(*i)++;
	while (str[*i])
	{
		if (str[*i] == '\'')
		{
			(*num_single)++;
			return ;
		}
		(*i)++;
	}
}

void	double_quotes(char *str, int *num_double, int *i)
{
	(*num_double)++;
	(*i)++;
	while (str[*i])
	{
		if (str[*i] == '"')
		{
			(*num_double)++;
			return ;
		}
		(*i)++;
	}
}

int	check_string(char *str)
{
	int	i;
	int	num_single;
	int	num_double;

	i = 0;
	num_single = 0;
	num_double = 0;
	while (str && str[i])
	{
		if (str[i] == '"')
			double_quotes(str, &num_double, &i);
		else if (str[i] == '\'')
			single_quotes(str, &num_single, &i);
		if (str[i] != 0)
			i++;
	}
	if ((num_double % 2 != 0) || (num_single % 2 != 0))
	{
		printf(" ERROR: quotation not closed\n");
		return (1);
	}
	return (0);
}