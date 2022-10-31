/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:42:50 by ihhrabar          #+#    #+#             */
/*   Updated: 2022/10/29 17:42:53 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H

# define FUNCTIONS_H

# define NONE_VALUE (void*)1
# define MAX_CAPACITY_REACHED -1
# define KEY_ALREADY_EXISTS -2

//Dictionary struct
typedef struct t_dict
{
	int		length;
	int		max_length;
	char	**keys;
	char	**values;
}	t_dict;
//Creates a new string with max capacity being set to max_length
t_dict		new_dict(int max_length);
//Deallocates space from the dict, and makes the dict unwritable
void		delete_dict(t_dict *dict);
//Returns the value from dictionary, located with the key.
//If value doesn't exist, NONE_VALUE is returned.
char		*dict_get_value(t_dict *d, char *key);
//Sets the value at the specified key to the dictionary.
//Returns 1 if successful, otherwise returns MAX_CAPACITY_REACHED
//if a dict cannot store more values, and returns KEY_ALREADY_EXISTS
//if an attempt was made to write to the same key twice.
int			dict_set_value(t_dict *d, char *key, char *value);

//Creates a new string on heap by copying str.
char		*new_str(char *str);
//Deallocates space from string.
void		delete_str(char *str);
//strcmp analogue.
int			str_compare(char *str1, char *str2);
//strlen analogue.
int			str_length(char *str);
//Returns 1 if the string only contains numeric characters, otherwise
//returns 0.
int			str_is_numeric(char *str);

//Allocates space for a new string and writes the result of addition
//of 2 numbers represented by strings a and b.
//char		*add_num_str(char *a, char *b); //Deprecated lol
//Allocates space for a new string and writes the result of subtraction
//of 2 numbers represented by strings a and b.
char		*sub_num_str(char *a, char *b);
//Returns 1 if a number represented by a is larger than a number
//represented by b, otherwise returns 0.
int			larger_num_str(char *a, char *b);
//Returns 1 if a number represented by a is equal to number
//represented by b, otherwise returns 0.
int			equal_num_str(char *a, char *b);
//Converts integer to string
char		*int_to_str(int n);

//Reads a .dict file and creates a string with its contents.
char		*read_number_naming_dictionary(char *file_path);
//Transforms .dict file contents into a t_dict struct.
t_dict		parse_number_naming_dictionary(char *dict_str);

//The star of the show.
int			process_num(char *num, t_dict dict, int *print_delim);
//Prints the number to stdout
void		print_num(char *num, t_dict dict, int *print_delim);
//Gets nearest number in the dictionary to the given argument
char		*get_nearest_num(char *num, t_dict dict);

//Prints string to stdout
void		print_str(char *str);

#endif
