/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:41:52 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/09 18:10:29 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "libft/libft.h"

char	*get_next_line(int fd);
char	*get_broken_line(int fd, char *brokenl, int rlen);
char	*get_fixed_line(const char *brokenl);
char	*get_next_brokenl(char *brokenl);

#endif
