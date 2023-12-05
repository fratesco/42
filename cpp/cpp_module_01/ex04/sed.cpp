#include "sed.hpp"

int	input_check(int	argc)
{
	if (argc > 4)
	{
		std::cout<<"Too many arguments\nValid inputs example: ./sed <filename> <string1> <string2>\n";
		exit (1);
	}
	else if (argc < 4)
	{
		std::cout<<"Too few arguments\nValid inputs example: ./sed <filename> <string1> <string2>\n";
		exit (1);
	}
	return (1);
}

int	main(int argc, char** argv)
{
	std::string	file_tmp;
	std::string	tmp;
	std::string file_save;
	char	buff[1];
	std::ifstream	file_old;
	std::ofstream	file_new;
	
	input_check(argc);
	file_old.open(argv[1]);
	if (!file_old.is_open())
	{
		std::cout<<"Unable to open "<<argv[1]<<", check permissions and/or if the file exists\n";
		return (1);
	}
	for (int i = 1; !file_old.rdstate();)
	{
		file_old.read(buff, i);
		if(!file_old.rdstate())
			file_tmp.push_back(buff[0]);
	}
	if (!file_old.eof())
	{
		std::cout<<"There was an error while reading the file\n";
		return (1);
	}
	file_save = argv[1];
	file_save.append(".replace");
	file_new.open(file_save);
	if(!file_new.is_open())
	{
		std::cout<<"Unable to create "<<file_save<<std::endl;
		file_old.close();
		return (1);
	}
	int	j = 0;
	for (int i = 0; i < file_tmp.length(); i++)
	{
		for(j = 0; (argv[2][j]) && argv[2][j] == (file_tmp.begin())[i + j]; j++);

		if (j == strlen(argv[2]))
		{
			tmp.append(argv[3]);
			i += strlen(argv[2]) - 1;
		}	
		else
			tmp.push_back((file_tmp.begin())[i]);
	}
	file_new.write(tmp.c_str(), tmp.size());
	file_old.close();
	file_new.close();
	return (0);
}