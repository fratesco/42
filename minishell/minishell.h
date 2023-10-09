/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:11:09 by fgolino           #+#    #+#             */
/*   Updated: 2023/10/09 15:49:21 by fgolino          ###   ########.fr       */
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
	int		instr_len; //numero di elementi nella matrice instr_token | è lo stesso valore di num_arg quando avremo split corretto
	int		instr_pid; //è il pid del processo figlio che sta esenguendo un comando, serve per poter aspettare che finisca e poter terminarlo in caso di int-sig
	int		received_signal; //valore scritto da wait();
	char	*user; //la variabile che contiene il valore della variabile globale USER
	char	*current_path; //l'attuale folder in cui sta lavorando il processo
	int		temp_stdout; //il salvataggio di stdout che serve per poterlo recuperare
	int		temp_fd; //il file descpitor del file che attualemente sostituisce stdout
	int		num_pipe; //il numero totale di pipe
	int		pos_pipe; //la posizione della pipe che adesso stiamo considerando (potrebbe essere ridondante vista la presenza di instr_end)
}	t_info;

void	start(t_info *info); //funzione che splitta l'intera riga letta da readline e la prepara all'analisi
void	free_matrix(char **matrix); //funzione che libera la memoria di una matrice
void	free_stuff(t_info *info, int flag); //funzione che libera tutta la memoria occupata dalla struttura globale
char	**pipe_finder(t_info *info); //funzione che trova la posizione di una pipe
void	signal_rewire(void); //funzione che modifica la risposta ai segnali ctrl-d e ctrl-c
void	signal_fork(void); //funzione che reimposta gli handler standard; viene chiamata nel processo figlio perchè eredita gli handler modificati dal genitore
void	signal_avoid(void);
void	int_child_alive(int signum);
void	interrupt(int signum); //nuovo handler del segnale ctrl-c
void	quitter(int signum); //nuovo handler del segnale ctrl-d
void	analizer(t_info *info); //funzione che capisce se la nuova riga presenta un comando valido e lo fa partire
void	dollar_handler(t_info *info); //funzione che si occupa di sostituire i $ con le rispettive variabili globali qualore esistano
char	*dollar_remover(char *str, int pos);
int		check_dollar(char *str);
char	*no_env(int start, int end, char *str);
void	pwd_handler(t_info *info); //funzione che imita il funzionamento di pwd
void	echo_handler(t_info *info); //funzione che imita il funzionamente di echo (con flag -n)
void	cd_handler(t_info *info); //funzione che imita il comportamento di cd
int		cd_loop(t_info *info);
void	env_handler(t_info *info); //funzione che imita il comportamento di env senza flag
void	unset_handler(t_info *info); //funzione che imita il comportamento di unset senza flag
void	export_handler(t_info *info); //funzione che imita il comportamento di export senza flag
void	try_find_do(t_info *info, char *name); //funzione che si occupa di controlla se esiste il comando scritto esiste ed è eseguibile, lo esegue qualore possibile
int		redirector(t_info *info); //funzione che modifica momentaneamente il stdout
void	get_environment(t_info *info, char **environment); //funzione che salva le variabili globali che ci servono e inizializza le variabili della struttura
void	executing(t_info *info); //funzione creata per acorciare il main, tutto quello che è scritto qui era scritto nel loop del main
int		check_string(char *str); //funzione che controlla se le quote della stringa siano correttamente chiuse
void	polish_tokens(t_info *info); //funzione che controlla la presenza di quotes nelle stringhe e fa partire quote_remover
void	single_quotes(char *str, int *num_single, int *i); //serve a check_string
void	double_quotes(char *str, int *num_single, int *i); //serve a check_string
int		quote_remover(char *str, char sep, size_t len); //funzione che rimuove le quotes dalle stringhe
int		keep_removing(char *str, int start); //serve a quote_remover
int		remove_more(char *str, int start, char needle); //serve a keep_removing
char	*triple_join(char *start, char *middle, char *end); //serve a unire 3 stringhe
char	**splitter(char *av, char sep, int stop, int *ac); //split migliorato che tiene conto delle virgolette e le salta
void	pip_index(t_info *info); //funzione che trova la posizione della prima pipe e la scrive in info.pos_pipe; viene utilizzato come stop di splitter;

//void	quote_splitter(char **tokens);

#endif