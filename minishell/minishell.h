/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:11:09 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/02 22:53:14 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define _XOPEN_SOURCE 700
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>

typedef struct s_info
{
	char	**global_path;
	char	*instruction;
	char	**instr_token;
	int		instr_len;
	int		instr_pid;
	char	*user;
	char	*current_path;
	int		temp_stdout;
	int		temp_fd;
	int		num_pipe;
	int		pos_pipe;
}	t_info;

void	start(void);
void	free_matrix(char **matrix);
void	free_stuff(void);
char	**pipe_finder(void);
void	signal_rewire(void);
void	interrupt(int signum);
void	quitter(int signum);
void	analizer(void);
void	pwd_handler(void);
int		redirector(void);
void	get_environment(void);
//int		check_string(char *str);
//void	quote_splitter(char **tokens);

#endif