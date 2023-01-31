/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:07:36 by fgolino           #+#    #+#             */
/*   Updated: 2023/01/31 16:34:04 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H
# define ERROR -1
# define FOUND 1
# define NOTHING 0
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef enum b_bool{FALSE, TRUE}	t_bool;

int		ft_printf(const char *str, ...);
void	ft_putstr_special(const char *str, int *n);
size_t	ft_strlen(const char *str);
int		check_special(const char *str);
int		parsing_checking(const char *str, va_list list);
void	ft_putchar(const char c, int *n);
void	conversion(const char c, va_list list);
void	ft_putnber_pointer(unsigned long pointer, int *n);
int		check(char *base);
void	print(char *num, int i, char *base, int *n);
int		check0(int nbr, char *b, int *n);
void	ft_putnbr_base(int nbr, char *base, int *n);

#endif