/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 00:25:19 by fgolino           #+#    #+#             */
/*   Updated: 2024/07/02 16:02:27 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
		{
			char **matrix = new char*[argc];
			int	i = 1;
			while (i < argc)
			{
				matrix[i - 1] = new char[strlen(argv[i]) + 1];
				strcpy(matrix[i - 1], argv[i]);
				int j;
				for (j = 0; matrix[i - 1][j]; j++)
					matrix[i - 1][j] = toupper(matrix[i - 1][j]);
				std::cout << matrix[i - 1];
				if (i < argc - 1)
				std::cout << ' ';
				i++;
			}
			while (i > 1)
				delete [] matrix[(i--) - 2];
			delete [] matrix;
			std::cout <<std::endl;
		}
	return (0);
}