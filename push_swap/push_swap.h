/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:28:30 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/10 18:42:43 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_instructions
{
	int				total;
	char			*command;
	t_instructions	*next;
}t_instructions;


int		check_parameters(char **params, int num);
int		check_status(long *stack, int len);
int		stack_inserter(char	**params, long **stack, int i);
void	swap(long **stack);
void	push(long **stack_a, long **stack_b, int *len_a, int *len_b);
void	rotate(long **stack, int len);
void	reverse_rotate(long **stack, int len);
#endif