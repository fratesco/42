/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:07:36 by fgolino           #+#    #+#             */
/*   Updated: 2023/04/22 13:47:45 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# define ERROR -1
# define FOUND 1
# define NOTHING 0
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>

typedef enum b_bool{FALSE, TRUE}	t_bool;

int		ft_printf(const char *str, ...);
void	ft_putstr_special(const char *str, size_t *n);
size_t	ft_strlen(const char *str);
int		check_special(const char *str);
int		parsing_checking(const char *str, va_list list, size_t *n);
void	ft_putchar(const char c, size_t *n);
void	conversion(const char c, va_list list, size_t *n);
void	ft_putnbr_pointer(unsigned long pointer, size_t *n);
void	print(char *num, int i, int base, size_t *n);
int		check0(int nbr, size_t *n);
void	ft_putnbr_hex(int nbr, int caser, size_t *n);
void	ft_putnbr(long nbr, size_t *n);
void	ft_putnbr_void(uintptr_t nbr, int caser, size_t *n);

#endif