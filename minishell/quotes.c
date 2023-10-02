/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:02:58 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/02 15:57:37 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

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

//int	new_check_string(char	*str)
//{
//	int	i;
//	int	n_single;
//	int	n_double;
//
//	i = 0;
//	n_single = 0;
//	n_double = 0;
//	while ()
//}

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

void	polish_tokens(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->instr_token && info->instr_token[i])
	{
		j = 0;
		while (info->instr_token[i] && info->instr_token[i][j])
		{
			if (info->instr_token[i][j] == '"')
			{
				quote_remover(info->instr_token[i], '"',
					ft_strlen(info->instr_token[i]));
				break ;
			}
			else if (info->instr_token[i][j] == '\'')
			{
				quote_remover(info->instr_token[i], '\'',
					ft_strlen(info->instr_token[i]));
				break ;
			}
			j++;
		}
		i++;
	}
}

int	quote_remover(char *str, char sep, size_t len)
{
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
	tmp = strdup(&(str[last + 1]));
	ft_strlcpy(&(str[first]), &(str[first + 1]), (last));
	ft_strlcpy(&(str[last - 1]), tmp, len);
	free(tmp);
	keep_removing(str, last - 1);
	return (last);
}
