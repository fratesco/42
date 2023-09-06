/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:02:58 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/06 16:39:00 by fgolino          ###   ########.fr       */
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

void	polish_tokens(void)
{
	int	i;
	int	j;

	i = 0;
	while (g_info.instr_token && g_info.instr_token[i])
	{
		j = 0;
		while (g_info.instr_token[i] && g_info.instr_token[i][j])
		{
			if (g_info.instr_token[i][j] == '"')
			{
				//g_info.instr_token[i] = 
					quote_remover(g_info.instr_token[i], '"');
				break ;
			}
			else if (g_info.instr_token[i][j] == '\'')
			{
				//g_info.instr_token[i] = 
					quote_remover(g_info.instr_token[i], '\'');
				break ;
			}
			j++;
		}
		i++;
	}
}

int	quote_remover(char *str, char sep)
{
	int		i;
	char	*tmp;
	int		first;
	int		last;

	first = 0;
	while (str && str[first])
	{
		if (str[first] == sep)
			break ;
		first++;
	}
	last = first + 1;
	while (str && str[last])
	{
		if (str[last] == sep)
			break ;
		last++;
	}
	i = ft_strlen(str);
	tmp = strdup(&(str[last + 1]));
	ft_strlcpy(&(str[first]), &(str[first + 1]), (last));
	ft_strlcpy(&(str[last - 1]), tmp, (i));
	free(tmp);
	keep_removing(str, last - 1);
	printf(" first :%i last :%i %s\n", first, last, str);
	return (last);
}
