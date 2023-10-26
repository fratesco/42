/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:34:18 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/26 18:04:14 by fgolino          ###   ########.fr       */
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

	// devi prendere tutto ciò che sta dopo il ">" fare una stringa e usarla come path per il file dove dobbiamo scrivere
	i = 0;
	while (str[start + i] && str[start + i] != '>' && str[start + i] != '<') //prendiamo la stringa fino a che non finisce o finché non troviamo un altro redirect
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(tmp, &str[start], i + 1);
	if (flag == 0)
		info->temp_out_fd = open(tmp, O_CREAT | O_WRONLY, 0666);
	if (flag == 1)
		info->temp_out_fd = open(tmp, O_CREAT | O_WRONLY | O_APPEND, 0666);
	free(tmp);
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
