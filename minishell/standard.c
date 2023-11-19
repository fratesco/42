/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:58:20 by fgolino           #+#    #+#             */
/*   Updated: 2023/11/19 17:53:16 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_stdin(t_info *info)
{
	if (info->tmp_fd)
	{
		tmp_file_creator(info, 2, 0);
		dup2(info->temp_stdin, STDIN_FILENO);
		tmp_file_creator(info, 3, 0);
	}
	if (info->temp_stdin)
	{
		if (info->temp_in_fd)
			close(info->temp_in_fd);
		dup2(info->temp_stdin, STDIN_FILENO);
		info->temp_in_fd = 0;
	}
		info->temp_stdin = 0;
}

void	reset_stdout(t_info *info)
{
	info->pos_pipe = 0;
	if (info->temp_stdout)
	{
		if (info->temp_out_fd)
			close(info->temp_out_fd);
		dup2(info->temp_stdout, STDOUT_FILENO);
		info->temp_stdout = 0;
		info->temp_out_fd = 0;
	}
}
