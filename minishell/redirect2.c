/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:34:18 by fgolino           #+#    #+#             */
/*   Updated: 2023/11/08 12:21:45 by fgolino          ###   ########.fr       */
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
	free(tmp);
	if (start == 0)
		ft_strlcpy(str, &str[i], ft_strlen(str));
	else if (start != 0 && info->end_save == -1)
		info->end_save = start - 1;
	if (info->temp_out_fd == -1)
	{
		info->is_error = 1;
		return ;
	}
	if (!info->temp_stdout)
		info->temp_stdout = dup(STDOUT_FILENO);
	dup2(info->temp_out_fd, 1);
}

void	input_delim(t_info *info, char *str, int start, int flag)
{
	int		i;
	char	*tmp;
	char	*get;
	char	buff[10000];
	char	**matrix;

	i = 0;
	matrix = 0;
	while (str[start + i] && str[start + i] != '>' && str[start + i] != '<')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(tmp, &str[start], i + 1);
	if (start == 0)
		ft_strlcpy(str, &str[i], ft_strlen(str));
	else if (start != 0 && info->end_save == -1)
		info->end_save = start - 1;
	printf("%i\n", info->end_save);
	if (!info->temp_stdin)
		info->temp_stdin = dup(STDIN_FILENO);
	i = 0;
	while (1)
	{
		if (i == 0)
			write(2, "> ", 2);
		read(STDIN_FILENO, &buff[i], 1);
		i++;
		if (buff[i - 1] == '\n')
		{
			buff[i] = 0;
			if (ft_strlen(buff) == ft_strlen(tmp) + 1)
			{
				if (ft_strncmp(buff, tmp, ft_strlen(buff)))
				{
					dup2(STDOUT_FILENO, 0);
					i = 0;
					
					while (i < flag)
						printf("%s", matrix[i++]);
				}
				break ;
			}
			matrix = matrix_crusher(matrix, buff);
			flag++;
			i = 0;
		}
	}
	free_matrix(matrix);
	free(tmp);
}
