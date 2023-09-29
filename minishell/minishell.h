/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:11:09 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/29 18:25:55 by fgolino          ###   ########.fr       */
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
	char	**global_path; //la variabile globale PATH
	char	*instruction; //l'intera stringa passata a minishell sul terminale. Da non confondere con current instruction che sarebbe l'ipotetica stringa che finisce su una pipe
	// cambio di programma, adesso instrcution sarà l'interea stringa passata, mentre instr_token sarà composto da un solo comando e i relativi argomenti e flags.
	// il check sulle pipe e redirect verrà fatto prima e verrano gestiti di conseguenza
	char	**instr_token; //matrice che contiene tutte le parole che compongono la current instruction
	int		instr_end; //posizione della pipe che termina la nostra current instruction
	int		instr_start; //inizio della current instruction
	int		current_arg; //l'attuale arg che stiamo guardando
	int		num_arg; //numero di arg che abbiamo nella current instruction
	int		instr_len; //lunghezza della stringa current instruction
	int		instr_pid; //è il pid del processo figlio che sta esenguendo un comando, serve per poter aspettare che finisca e poter terminarlo in caso di int-sig
	char	*user; //la variabile che contiene il valore della variabile globale USER
	char	*current_path; //l'attuale folder in cui sta lavorando il processo
	int		temp_stdout; //il salvataggio di stdout che serve per poterlo recuperare
	int		temp_fd; //il file descpitor del file che attualemente sostituisce stdout
	int		num_pipe; //il numero totale di pipe
	int		*pos_pipe; //la posizione della pipe che adesso stiamo considerando (potrebbe essere ridondante vista la presenza di instr_end)
}	t_info;

void	start(t_info *info); //funzione che splitta l'intera riga letta da readline e la prepara all'analisi
void	free_matrix(char **matrix); //funzione che libera la memoria di una matrice
void	free_stuff(t_info info); //funzione che libera tutta la memoria occupata dalla struttura globale
char	**pipe_finder(t_info *info); //funzione che trova la posizione di una pipe
void	signal_rewire(void); //funzione che modifica la risposta ai segnali ctrl-d e ctrl-c
void	interrupt(int signum); //nuovo handler del segnale ctrl-c
void	quitter(int signum); //nuovo handler del segnale ctrl-d
void	analizer(t_info *info); //funzione che capisce se la nuova riga presenta un comando valido e lo fa partire
void	pwd_handler(t_info *info); //funzione che imita il funzionamento di pwd
void	echo_handler(t_info *info); //funzione che imita il funzionamente di echo (con flag -n)
void	cd_handler(t_info *info); //funzione che imita il comportamento di cd
int		redirector(t_info *info); //funzione che modifica momentaneamente il stdout
void	get_environment(t_info *info); //funzione che salva le variabili globali che ci servono e inizializza le variabili della struttura
int		check_string(char *str); //funzione che controlla se le quote della stringa siano correttamente chiuse
void	polish_tokens(t_info *info); //funzione che controlla la presenza di quotes nelle stringhe e fa partire quote_remover
void	single_quotes(char *str, int *num_single, int *i); //serve a check_string
void	double_quotes(char *str, int *num_single, int *i); //serve a check_string
int		quote_remover(char *str, char sep); //funzione che rimuove le quotes dalle stringhe
int		keep_removing(char *str, int start); //serve a quote_remover
int		remove_more(char *str, int start, char needle); //serve a keep_removing
char	*triple_join(char *start, char *middle, char *end);

//void	quote_splitter(char **tokens);

#endif