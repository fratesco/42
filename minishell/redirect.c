/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:06:49 by fgolino           #+#    #+#             */
/*   Updated: 2023/11/08 12:09:09 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

int	check_redirection(char *str, t_info *info, int row, int i)
{
	while (str && str[i] && info->use_redirect[info->num_redirect] != 10)
	{
		if (str[i] == '>')
		{
			if (info->use_redirect[info->num_redirect++] == 1)
			{
				output_router(info, str, i, row);
				if (str[i + 1] == '<')
					i++;
			}
		}
		else if (str[i] == '<')
		{
			if (info->use_redirect[info->num_redirect++] == 1)
			{
				input_router(info, str, i, row);
				if (str[i + 1] == '<')
					i++;
			}
		}
		i++;
	}
	if (info->is_error != UNEXPECTED && info->end_save != -1)
		str[info->end_save] = 0;
	return (0);
}

int	redirector(t_info *info)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	info->num_redirect = 0;
	while (info->instr_token[i])
	{
		info->end_save = -1;
		info->is_error = 0;
		if (check_redirection(info->instr_token[i], info, i, 0))
		{
			info->exit_status = 2;
			// qui aggiungi i vari tipi di exit_status a seconda del tipo di errore || 1 per permission deniend ecc...
			return (1);
		}
		i++;
	}
	return (0);
}

void	output_router(t_info *info, char *str, int col, int row)
{
	int		i;

	i = col + 1;
	if (str[i] == '>')
	{
		if (info->use_redirect[info->num_redirect] == 1 && str[i + 1])
			fd_output(info, str, 1 + i, 1);
		else if (info->use_redirect[info->num_redirect] == 1 && !str[i + 1])
		{
			if (info->instr_token[row + 1])
				fd_output(info, info->instr_token[row + 1], 0, 1);
			if (info->instr_token[row + 1] && info->is_error != 1)
				str[i - 1] = 0;
		}
	}
	else if (str[i] == 0)
	{
		if (info->instr_token[row + 1])
			fd_output(info, info->instr_token[row + 1], 0, 0);
		if (info->instr_token[row + 1] && info->is_error != 1)
			str[i - 1] = 0;
	}
	else if (str[i] != 0)
		fd_output(info, str, i, 0);
}

void	input_router(t_info *info, char *str, int col, int row)
{
	int		i;

	i = col + 1;
	if (str[i] == '<')
	{
		if (info->use_redirect[info->num_redirect++] == 1 && str[i + 1])
			return (input_delim(info, str, i + 1, 0));
		else if (info->use_redirect[info->num_redirect++] == 1 && !str[i + 1])
		{
			if (info->instr_token[row + 1])
				input_delim(info, info->instr_token[row + 1], 0, 0);
			if (info->instr_token[row + 1] && info->is_error != 1)
				str[i - 1] = 0;
		}
	}
	else if (str[i] == 0)
	{
		if (info->instr_token[row + 1])
			fd_input(info, info->instr_token[row + 1], 0);
		if (info->instr_token[row + 1] && info->is_error != 1)
			str[i - 1] = 0;
	}
	else if (str[i] != 0)
		fd_input(info, str, i);
}

void	fd_input(t_info *info, char *str, int start)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[start + i] && str[start + i] != '>' && str[start + i] != '<')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(tmp, &str[start], i + 1);
	info->temp_in_fd = open(tmp, O_RDONLY);
	free(tmp);
	if (start == 0)
		ft_strlcpy(str, &str[i], ft_strlen(str));
	else if (start != 0 && info->end_save == -1)
		info->end_save = start - 1;
	if (info->temp_in_fd == -1)
	{
		info->is_error = 1;
		return ;
	}
	if (!info->temp_stdin)
		info->temp_stdin = dup(STDIN_FILENO);
	dup2(info->temp_in_fd, 0);
}
