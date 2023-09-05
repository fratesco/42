/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:02:58 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/05 17:58:46 by fgolino          ###   ########.fr       */
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
				g_info.instr_token[i] = 
					quote_remover(g_info.instr_token[i], '"', -1);
				break ;
			}
			else if (g_info.instr_token[i][j] == '\'')
			{
				g_info.instr_token[i] = 
					quote_remover(g_info.instr_token[i], '\'', -1);
				break ;
			}
			j++;
		}
		i++;
	}
}

char	*quote_remover(char *str, char sep, int stop)
{
	char	*tmp;
	int		first;
	int		last;

	first = 0;
	while (str && str[first])
	{
		if (str[first++] == sep)
			break ;
		first++;
	}
	last = first;
	while (str && str[last])
	{
		if (str[last] == sep)
			break ;
		last++;
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str)));
	ft_strlcpy(tmp, str, first + 1);
	ft_strlcpy(&(tmp[first - 1]), &(str[first]), (last));
	ft_strlcpy(&(tmp[last - 1]), &(str[last]), (ft_strlen(str) - last));
	//non funziona per niente devi controllare ancora testa sucasucasuca"sucate"
	//tmp = keep_removing(tmp, last, sep);
	printf(" first :%i last :%i %s\n", first, last, tmp);
	free(str);
	return (tmp);
}
