/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:22:56 by ihhrabar          #+#    #+#             */
/*   Updated: 2022/10/30 13:22:58 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char	*get_nearest_num(char *num, t_dict dict)
{
	char	*nearest;
	int		i;

	nearest = 0;
	i = 0;
	while (i < dict.length)
	{
		if (larger_num_str(num, dict.keys[i])
			|| equal_num_str(num, dict.keys[i]))
		{
			if (nearest == 0)
				nearest = dict.keys[i];
			else if (larger_num_str(dict.keys[i], nearest))
			{
				nearest = dict.keys[i];
			}
		}
		i++;
	}
	return (nearest);
}

char	*dec_number(char *num, char *n_num, int *aux_counter)
{
	char	*last_num;

	*aux_counter = 0;
	while (larger_num_str(num, n_num) || equal_num_str(num, n_num))
	{
		last_num = num;
		num = sub_num_str(num, n_num);
		delete_str(last_num);
		(*aux_counter)++;
	}
	return (num);
}

//printf("num: %s, n_num: %s\n", num, n_num);
//	printf("cnu: %s\n", num);
//printf("aux: %s\n", aux_c_str);
int	process_helper(char *num, t_dict dict, char *n_num, int *print_delim)
{
	int		aux_counter;
	char	*aux_c_str;

	num = new_str(num);
	num = dec_number(num, n_num, &aux_counter);
	aux_c_str = int_to_str(aux_counter);
	if ((larger_num_str(n_num, "99") || aux_counter > 1)
		&& (!process_num(aux_c_str, dict, print_delim)))
	{
		delete_str(aux_c_str);
		delete_str(num);
		return (0);
	}
	print_num(n_num, dict, print_delim);
	if (larger_num_str(num, "0"))
		process_num(num, dict, print_delim);
	delete_str(aux_c_str);
	delete_str(num);
	return (1);
}

int	process_num(char *num, t_dict dict, int *print_delim)
{
	char	*nearest_num;
	int		result;

	num = new_str(num);
	nearest_num = get_nearest_num(num, dict);
	if (!nearest_num)
	{
		delete_str(num);
		return (0);
	}
	if (equal_num_str(num, nearest_num))
	{
		print_num(num, dict, print_delim);
		delete_str(num);
		return (1);
	}
	result = process_helper(num, dict, nearest_num, print_delim);
	delete_str(num);
	return (result);
}
