/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:28:30 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/14 17:00:58 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	long					value;
	struct s_stack			*next;
	int						biggest;
}t_stack;

t_stack			*new(int value);
void			clear_node(t_stack **list);
int				check_parameters(char **params, int num);
int				check_status(t_stack *stack, int len);
void			swap(long **stack);
void			push(long **stack_a, long **stack_b, int *len_a, int *len_b);
void			rotate(long **stack, int len);
void			reverse_rotate(long **stack, int len);
#endif