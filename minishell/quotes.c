/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:02:58 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/03 16:47:02 by fgolino          ###   ########.fr       */
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
					quote_remover(g_info.instr_token[i], '"');
				break ;
			}
			else if (g_info.instr_token[i][j] == '\'')
			{
				g_info.instr_token[i] = 
					quote_remover(g_info.instr_token[i], '\'');
				break ;
			}
			j++;
		}
		i++;
	}
}

char	*quote_remover(char *str, char sep)
{
	char	*tmp;
	int		first;
	int		last;

	first = 0;
	last = ft_strlen(str) - 1;
	while (str && str[first])
	{
		if (str[first++] == sep)
			break ;
	}
	while (str && last >= 0)
	{
		if (str[last--] == sep)
			break ;
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) - 1));
	ft_strlcpy(tmp, str, first + 1);
	ft_strlcpy(&(tmp[first]), &(str[first + 1]), (last - first));
	ft_strlcpy(&(tmp[last - 1]), &(str[last + 1]), (ft_strlen(str) - last));
	//qui il programma deve controllare se ci sono altre virgolette dello stesso tipo fino a last
	//deve poi controllare se ci sono altre virgolette anche diverse dopo last
	free(str);
	return (tmp);
}
