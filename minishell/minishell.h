/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:11:09 by fgolino           #+#    #+#             */
/*   Updated: 2023/12/15 15:15:40 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define _XOPEN_SOURCE 700
# define REMOVE_STR -1
# define REWRITTEN_STR 0
# define UNEXPECTED 1
# define PERMISSION 2
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <stdbool.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>

typedef struct s_info
{
	char	**global_path;
	char	**environment;
	char	*instruction;
	int		total_instructions;
	char	**instr_token;
	int		instr_end;
	int		instr_start;
	int		current_arg;
	int		num_arg;
	int		instr_pid;
	int		exit_status;
	int		is_error;
	char	*str_error;
	int		received_signal;
	char	*user;
	char	*current_path;
	int		temp_stdout;
	int		temp_stdin;
	int		temp_out_fd;
	int		temp_in_fd;
	int		num_pipe;
	int		pos_pipe;
	int		num_redirect;
	int		*use_redirect;
	int		end_save;
	char	*save_tmp;
	int		save_index;
	int		status_export_flag;
	int		tmp_fd;
	int		pipe_fd1[2];
	int		pipe_fd2[2];
	char	**tmp_matrix;
}	t_info;

void	no_end(t_info *info, int flag, char *tmp, char *buff);
int		tmp_function(t_info *info, char *buff, char *tmp, int flag);
void	tmp_function2(t_info *info, char **matrix, int i, int flag);
void	matrix_cleaner(char ***m, int *i);
void	export_exec(t_info *info, char **tmp, int arg);
void	export_no_arg(t_info *info, int i, int j);
void	p_export_no_arg(char **tmp);
int		export_checker(t_info *info, char *str);
void	start(t_info *info);
void	free_matrix(char **matrix);
void	free_stuff(t_info *info, int flag);
void	signal_rewire(void);
void	signal_fork(void);
void	signal_avoid(void);
void	int_child_alive(int signum);
void	interrupt(int signum);
void	quitter(int signum);
void	analizer(t_info *info, int i, int j);
void	clean_tokens(t_info *info);
void	dollar_handler(t_info *info);
char	*dollar_remover(t_info *info, char *str, int pos);
int		check_dollar(char *str);
char	*no_env(t_info *info, int start, int end, char *str);
char	*get_global(char **matrix, char *str);
char	*dollar_exit(char *str, t_info *info);
void	pwd_handler(t_info *info);
void	echo_handler(t_info *info);
void	cd_handler(t_info *info);
int		cd_loop(t_info *info, int i);
void	env_handler(t_info *info);
void	unset_handler(t_info *info, int arg, int i);
void	export_handler(t_info *info, int arg, int f, int ff);
int		token_checker(t_info *info, int arg);
void	exit_handler(t_info *info);
void	try_find_do(t_info *info, char *name);
int		redirector(t_info *info);
int		check_redirection(char *str, t_info *info, int row, int i);
void	output_router(t_info *info, char *str, int col, int row);
void	input_router(t_info *info, char *str, int col, int row);
void	fd_input(t_info *info, char *str, int start);
void	input_delim(t_info *info, char *str, int start, int flag);
void	fd_output(t_info *info, char *str, int start, int flag);
void	reset_stdin(t_info *info);
void	reset_stdout(t_info *info);
void	reset_all(t_info *info);
void	get_environment(t_info *info, char **environment);
void	executing(t_info *info);
int		check_string(char *str);
void	polish_tokens(t_info *info);
void	single_quotes(char *str, int *num_single, int *i);
void	double_quotes(char *str, int *num_single, int *i);
int		quote_remover(char *str, char sep, size_t len);
int		keep_removing(char *str, int start, int stop);
int		remove_more(char *str, int start, char needle);
char	*triple_join(char *start, char *middle, char *end);
char	**splitter(char *av, char sep, int stop, int *ac);
void	pip_index(t_info *info, int i, char t);
void	tmp_file_creator(t_info *info, int action, char **matr);
void	pipe_manager(t_info *info);
void	count_redirect(t_info *info, int i, int j, int count);
void	count_allocate(t_info *info);
char	**matrix_crusher(char **matrix, char *str);
char	**matrix_remover(char **matrix, int ind);
void	tmp_error(t_info *info, char *tmp);

#endif