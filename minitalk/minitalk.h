/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:40:29 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/06 12:01:38 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

char	*g_server;
int		g_client;
void	client_receive(void);
void	server_receive(void);
int		client_send(char *str, int pid);
#endif