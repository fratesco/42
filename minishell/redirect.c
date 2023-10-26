/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:06:49 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/26 10:34:05 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

int	check_redirection(char *str, t_info *info)
{
	int		i;

	i = 0;
	info->num_redirect = 0;
	while (str[i])
	{
		if (str[i] == '>')
		{
			if (info->use_redirect[info->num_redirect++] == 1)
				output_router(info, str, i);
		}
		else if (str[i] == '<')
		{
			if (info->use_redirect[info->num_redirect++] == 1)
				input_router(info, str, i);
		}
		if (info->is_error == 1)
			return (1);
		i++;
	}
	return (0);
}

int	redirector(t_info *info)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (info->instr_token[i])
	{
		if (check_redirection(info->instr_token[i], info))
		{
			info->exit_status = 2;
			// qui aggiungi i vari tipi di exit_status a seconda del tipo di errore || 1 per permission deniend ecc...
			return (1);
		}
		else
		{
			
		}
		i++;
	}	
	return (0);
}

void	output_router(t_info *info, char *str, int col)
{
	int		i;
	char	c;

	i = col + 1;
	c = 0;
	if (str[i] == '>')
	{
		if (info->use_redirect[info->num_redirect++] == 1)
			return ; // qui fai open in append mode
	}

}

void	input_router(t_info *info, char *str, int col)
{
	int		i;

	i = col + 1;
	if (str[i] == '<')
	{
		if (info->use_redirect[info->num_redirect++] == 1)
			return ; // input_delim()
	}
	if (str[i] == 0)
	{
		if ((str + 1))
			return (fd_input(info, (str + 1), 0)); //gli inviamo la stringa dopo se esiste(bisogna fare il check di questo)
		//else
			//errore
	}
	if (str[i] != 0)
		fd_input(info, str, 1);
}

void	fd_input(t_info *info, char *str, int start)
{
	int		i;
	char	*tmp;

	// devi prendere tutto ciò che sta dopo il ">" fare una stringa e usarla come path per il file dove dobbiamo scrivere
	i = 0;
	while (str[start + i] && str[start + i] != '>' && str[start + i] != '<') //prendiamo la stringa fino a che non finisce o finché non troviamo un altro redirect
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(tmp, &str[start], i + 1);
	info->temp_in_fd = open(tmp, 0, O_RDONLY);
	free(tmp);
	if (info->temp_in_fd == 0)
	{
		info->is_error = 1;
		return ;
	}
	info->temp_stdin = dup(STDIN_FILENO);
	dup2(info->temp_in_fd, 0);
	return ;
}
