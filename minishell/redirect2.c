/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:34:18 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/27 16:04:02 by fgolino          ###   ########.fr       */
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
	info->use_redirect = (int *)malloc(sizeof(int) * count);
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
	while (flag != -1)
		flag--;
	str[start + flag] = 0; //purtroppo non funziona in tutti i casi, andrebbe fatto dopo che abbiamo valutato tutti i opossibili redirect
	if (info->temp_out_fd == -1)
	{
		printf("error\n");
		info->is_error = 1;
		return ;
	}
	info->temp_stdout = dup(STDOUT_FILENO);
	dup2(info->temp_out_fd, 1);
	return ;
}
