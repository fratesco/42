/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:28:30 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/17 12:08:52 by fgolino          ###   ########.fr       */
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
int				stack_size(t_stack *stack);
int				check_parameters(char **params, int num);
int				check_status(t_stack *stack, int len);
t_stack			*stack_generator(int len, char **argv, int i);
void			visualize_stack(t_stack *stack);
void			swap(t_stack **stack);
void			push(t_stack **stack1, t_stack **stack2);
void			rotate(t_stack **stack);
void			reverse_rotate(t_stack **stack);
void			find_biggest(t_stack **stack);
#endif