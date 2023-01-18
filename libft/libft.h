/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:38:34 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/17 17:57:29 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_isalpha(int letter);
int		ft_isdigit(int i);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_strlen(char *str);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(char *str1, char *str2, unsigned int n);
void	*ft_memset(void *buffer, int byte, int len);
void	ft_bzero(void *str, int len);
void	*ft_memmove(void *dst, void *src, int len);
void	*ft_memcpy(void *dst, void *src, int len);
char	*ft_strchr(char *str, int c);

#endif