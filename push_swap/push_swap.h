/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:28:30 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/13 08:42:44 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_instructions
{
	char			*command;
	t_instructions	*next;
}t_instructions;

t_instructions	*new(char *instruction);
void			add_back(t_instructions **list, t_instructions *new);
void			add_instruction(t_instructions **list, char *instruction);
void			clear_node(t_instructions **list);
int				check_parameters(char **params, int num);
int				check_status(long *stack, int len);
int				stack_inserter(char	**params, long **stack, int i);
void			swap(long **stack, t_instructions **list);
void			push(long **stack_a, long **stack_b, int *len_a, int *len_b);
void			rotate(long **stack, int len, t_instructions **list);
void			reverse_rotate(long **stack, int len, t_instructions **list);
#endif