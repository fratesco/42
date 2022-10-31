/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:50:52 by ihhrabar          #+#    #+#             */
/*   Updated: 2022/10/30 12:50:53 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>

#define DEFAULT_PATH "numbers.dict"

void	handle_args(int argc, char *argv[], char **d_path, char **i_num)
{
	if (argc == 2)
	{
		*i_num = argv[1];
		*d_path = DEFAULT_PATH;
	}
	else if (argc == 3)
	{
		*d_path = argv[1];
		*i_num = argv[2];
	}
	else
	{
		*i_num = 0;
		*d_path = 0;
	}
}

void	prepare_and_do_the_thing(char *i_num, char *dict_str)
{
	t_dict		dict;
	int			print_delim;

	print_delim = 0;
	if (!dict_str)
	{
		print_str("Dict Error");
		return ;
	}
	dict = parse_number_naming_dictionary(dict_str);
	if (dict.max_length == -1)
	{
		print_str("Dict Error");
		return ;
	}
	process_num(i_num, dict, &print_delim);
	print_str("");
	delete_dict(&dict);
}

int	main(int argc, char *argv[])
{
	char	*dict_path;
	char	*input_num;
	char	*dict_str;

	input_num = 0;
	dict_path = 0;
	handle_args(argc, argv, &dict_path, &input_num);
	if (input_num == 0 || !str_is_numeric(input_num))
	{
		print_str("Error");
		return (0);
	}
	dict_str = read_number_naming_dictionary(dict_path);
	prepare_and_do_the_thing(input_num, dict_str);
	delete_str(dict_str);
	return (0);
}
