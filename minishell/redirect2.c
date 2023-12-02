/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:34:18 by fgolino           #+#    #+#             */
/*   Updated: 2023/12/02 12:22:08 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

void	count_allocate(t_info *info)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (info->instr_token && info->instr_token[i])
	{
		j = 0;
		while (info->instr_token[i][j])
		{
			if (info->instr_token[i][j] == '>' ||
				info->instr_token[i][j] == '<')
				count++;
			j++;
		}
		i++;
	}
	info->use_redirect = (int *)malloc((sizeof(int) * (1 + count)));
}

void	fd_output(t_info *info, char *str, int start, int flag)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[start + i] && str[start + i] != '>' && str[start + i] != '<')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(tmp, &str[start], i + 1);
	if (flag == 0)
		info->temp_out_fd = open(tmp, O_CREAT | O_WRONLY, 0666);
	if (flag == 1 && info->num_redirect++)
		info->temp_out_fd = open(tmp, O_CREAT | O_WRONLY | O_APPEND, 0666);
	if (start == 0)
		ft_strlcpy(str, &str[i], ft_strlen(str));
	else if (start != 0 && info->end_save == -1)
		info->end_save = start - 1;
	if (info->temp_out_fd == -1)
	{
		if (info->is_error == 0)
			info->is_error = errno;
		if (!info->str_error)
			info->str_error = strdup(tmp);
		return ;
	}
	free(tmp);
	if (!info->temp_stdout)
		info->temp_stdout = dup(STDOUT_FILENO);
	dup2(info->temp_out_fd, 1);
}

void	input_delim(t_info *info, char *str, int start, int flag)
{
	int		i;
	char	*tmp;
	char	buff[10000];

	i = 0;
	info->tmp_matrix = 0;
	while (str[start + i] && str[start + i] != '>' && str[start + i] != '<')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(tmp, &str[start], i + 1);
	if (start == 0)
		ft_strlcpy(str, &str[i], ft_strlen(str));
	else if (start != 0 && info->end_save == -1)
		info->end_save = start - 1;
	if (!info->temp_stdin)
		info->temp_stdin = dup(STDIN_FILENO);
	i = 0;
	if (info->tmp_fd)
		reset_stdin(info);
	no_end(info, flag, tmp, buff);
	free_matrix(info->tmp_matrix);
	free(tmp);
}

void	no_end(t_info *info, int flag, char *tmp, char *buff)
{
	int		i;

	i = 0;
	while (1)
	{
		if (i == 0)
			write(2, "> ", 2);
		if (!read(STDIN_FILENO, &buff[i], 1))
		{
			tmp_function2(info, info->tmp_matrix, i, flag);
			printf("\nwarning: here-document at line %i ", i + 1);
			printf("delimited by end-of-file (wanted `%s')\n", tmp);
			break ;
		}
		i++;
		if (buff[i - 1] == '\n')
		{
			buff[i] = 0;
			if (tmp_function(info, buff, tmp, flag))
				break ;
			flag++;
			i = 0;
		}
	}
}

int	tmp_function(t_info *info, char *buff, char *tmp, int flag)
{
	int		i;
	char	**boh;

	if (ft_strlen(buff) == ft_strlen(tmp) + 1)
	{
		if (!ft_strncmp(buff, tmp, ft_strlen(tmp)))
		{
			tmp_file_creator(info, 0, 0);
			if (!info->temp_stdout)
				info->temp_stdout = dup(STDOUT_FILENO);
			dup2(info->tmp_fd, STDOUT_FILENO);
			i = 0;
			while (i < flag)
				printf("%s", info->tmp_matrix[i++]);
			tmp_file_creator(info, 2, 0);
			tmp_file_creator(info, 1, 0);
			dup2(info->temp_stdout, STDOUT_FILENO);
			dup2(info->tmp_fd, 0);
			return (1);
		}
	}
	boh = info->tmp_matrix;
	info->tmp_matrix = matrix_crusher(info->tmp_matrix, buff);
	free_matrix(boh);
	return (0);
}

void	tmp_function2(t_info *info, char **matrix, int i, int flag)
{
	if (!info->temp_stdout)
	info->temp_stdout = dup(STDOUT_FILENO);
	dup2(2, STDOUT_FILENO);
	tmp_file_creator(info, 0, 0);
	dup2(info->tmp_fd, STDOUT_FILENO);
	i == 0;
	while (i < flag)
		printf("%s", matrix[i++]);
	tmp_file_creator(info, 2, 0);
	tmp_file_creator(info, 1, 0);
	dup2(info->temp_stdout, STDOUT_FILENO);	
	dup2(info->tmp_fd, 0);
}
