/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:40:29 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/07 16:08:12 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	server_receive2(int sign);
void	server_receive(int sign);
int		client_send(char *str, int pid);
void	bit_sender(int unit, int pid);
void	get_stuff(void);
void	client_receive_continue(int sign);
void	client_all_received(int sign);
#endif