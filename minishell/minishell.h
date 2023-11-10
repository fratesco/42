/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:11:09 by fgolino           #+#    #+#             */
/*   Updated: 2023/11/10 11:43:27 by fgolino          ###   ########.fr       */
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
	char	**global_path; //la variabile globale PATH
	char	**environment; //contiene tutte le variabili globali e locali
	char	*instruction; //l'intera stringa passata a minishell sul terminale.
	// cambio di programma, adesso instrcution sarà l'interea stringa passata, mentre instr_token sarà composto da un solo comando e i relativi argomenti e flags.
	// il check sulle pipe e redirect verrà fatto prima e verrano gestiti di conseguenza
	char	**instr_token; //matrice che contiene tutte le parole che compongono la current instruction
	int		instr_end; //posizione della pipe che termina la nostra current instruction
	int		instr_start; //inizio della current instruction
	int		current_arg; //l'attuale arg che stiamo guardando
	int		num_arg; //numero di arg che abbiamo nella current instruction
	int		instr_pid; //è il pid del processo figlio che sta esenguendo un comando, serve per poter aspettare che finisca e poter terminarlo in caso di int-sig
	int		exit_status; //l'exit status dell'ultimo processo figlio terminato
	int		is_error; //variabile che viene usata per comprendere se qualcosa non è andato in qualche funzione precedente|| tutto quello che fa è evitare casini con codice lungo
	int		received_signal; //valore scritto da wait();
	char	*user; //la variabile che contiene il valore della variabile globale USER
	char	*current_path; //l'attuale folder in cui sta lavorando il processo
	int		temp_stdout; //il salvataggio di stdout che serve per poterlo recuperare
	int		temp_stdin; //il salvataggio di stdin che servec per poterlo recuperare
	int		temp_out_fd; //il file descpitor del file che attualmente sostituisce stdout
	int		temp_in_fd; //il file descriptor del file che attualmente sostituisce stdin
	int		num_pipe; //il numero totale di pipe
	int		pos_pipe; //la posizione della pipe che adesso stiamo considerando (potrebbe essere ridondante vista la presenza di instr_end)
	int		num_redirect; //numero totale di redirect
	int		*use_redirect; //attribuisce 1 o 0 alle redirect nell'ordine che vengono lette in modo da capire se vanno ignorate (dentro virgolette) oppure no
	int		end_save; //indice di dove finisce quello che deve essere salvato prima di un redirect
	char	*save_tmp; //utilizzato per salvare momentaneamente le parole che precedono il primo > o <
	int		save_index; // sempre per la cosa qui sopra serve a entrare nel numero massimo di righe
	int		status_export_flag;
	int		tmp_fd; //serve a salvare fd del file che usiamo come stdin per le pipe e input_delim
}	t_info;

void	matrix_cleaner(char ***m, int i);
void	export_exec(t_info *info, char **tmp, int arg);
void 	export_no_arg(t_info *info, int i, int j);
void 	p_export_no_arg(char **tmp);
int 	export_checker(t_info *info, char *str);
void	start(t_info *info); //funzione che splitta l'intera riga letta da readline e la prepara all'analisi
void	free_matrix(char **matrix); //funzione che libera la memoria di una matrice
void	free_stuff(t_info *info, int flag); //funzione che libera tutta la memoria occupata dalla struttura globale
void	signal_rewire(void); //funzione che modifica la risposta ai segnali ctrl-d e ctrl-c
void	signal_fork(void); //funzione che reimposta gli handler standard; viene chiamata nel processo figlio perchè eredita gli handler modificati dal genitore
void	signal_avoid(void); //funzione che imposta int_child_alive come handler di SIG_INT
void	int_child_alive(int signum); //handler per ctrl-c per il processo genitore quando viene generato un processo figlio
void	interrupt(int signum); //nuovo handler del segnale ctrl-c
void	quitter(int signum); //nuovo handler del segnale ctrl-d
void	analizer(t_info *info); //funzione che capisce se la nuova riga presenta un comando valido e lo fa partire
void	dollar_handler(t_info *info); //funzione che si occupa di sostituire i $ con le rispettive variabili globali qualore esistano
char	*dollar_remover(t_info *info, char *str, int pos); //controlla che esista la variabile globale con nome uguale ai caratteri dopo il $
int		check_dollar(char *str); //controlla che esista un $ valido e che debba essere sostituito
char	*no_env(t_info *info, int start, int end, char *str); //caso in cui non esiste la variabile globale e quindi sostituisce il nulla
char	*get_global(char **matrix, char *str);
char	*dollar_exit(char *str, t_info *info); //questa funzione si occupa di gestire il caso di "$?"
void	pwd_handler(t_info *info); //funzione che imita il funzionamento di pwd
void	echo_handler(t_info *info); //funzione che imita il funzionamente di echo (con flag -n)
void	cd_handler(t_info *info); //funzione che imita il comportamento di cd
int		cd_loop(t_info *info); //funzione continuo di cd || fatta per entrare nelle 25 righe
void	env_handler(t_info *info); //funzione che imita il comportamento di env senza flag
void	unset_handler(t_info *info, int arg, int i); //funzione che imita il comportamento di unset senza flag
void	export_handler(t_info *info, int arg, int f, int ff); //funzione che imita il comportamento di export senza flag
int 	token_checker(t_info *info, int arg);
void	exit_handler(t_info *info); //funzione che imita il comportamento di exit 
void	try_find_do(t_info *info, char *name); //funzione che si occupa di controlla se esiste il comando scritto esiste ed è eseguibile, lo esegue qualore possibile
int		redirector(t_info *info); //funzione che cerca le redirections nei tokens
int		check_redirection(char *str, t_info *info, int row, int i);
void	output_router(t_info *info, char *str, int col, int row);
void	input_router(t_info *info, char *str, int col, int row);
void	fd_input(t_info *info, char *str, int start);
void	input_delim(t_info *info, char *str, int start, int flag);
void	fd_output(t_info *info, char *str, int start, int flag);
void	get_environment(t_info *info, char **environment); //funzione che salva le variabili globali che ci servono e inizializza le variabili della struttura
void	executing(t_info *info); //funzione creata per acorciare il main, tutto quello che è scritto qui era scritto nel loop del main
int		check_string(char *str); //funzione che controlla se le quote della stringa siano correttamente chiuse
void	polish_tokens(t_info *info); //funzione che controlla la presenza di quotes nelle stringhe e fa partire quote_remover
void	single_quotes(char *str, int *num_single, int *i); //serve a check_string
void	double_quotes(char *str, int *num_single, int *i); //serve a check_string
int		quote_remover(char *str, char sep, size_t len); //funzione che rimuove le quotes dalle stringhe
int		keep_removing(char *str, int start, int stop); //serve a quote_remover
int		remove_more(char *str, int start, char needle); //serve a keep_removing
char	*triple_join(char *start, char *middle, char *end); //serve a unire 3 stringhe
char	**splitter(char *av, char sep, int stop, int *ac); //split migliorato che tiene conto delle virgolette e le salta
void	pip_index(t_info *info); //funzione che trova la posizione della prima pipe e la scrive in info.pos_pipe; viene utilizzato come stop di splitter;
void	tmp_file_creator(t_info *info, int action); //funzione che creare un file temporaneo in cui scriviamo e poi sostituiamo a stdin
void	count_redirect(t_info *info, int i, int j, int count); //
void	count_allocate(t_info *info);
char	**matrix_crusher(char **matrix, char *str); // creaa una copia di matrix a cui viene aggiunta str alla fine 
char	**matrix_remover(char **matrix, int ind); // rimuove la stringha con indice ind dalla matriche matrix (in realtà ne fa una copia senza quella stringa)

//void	quote_splitter(char **tokens);

#endif