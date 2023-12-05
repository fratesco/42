#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
		std::cout<<"Harlfileter takes only one argument\n";
	else
	{
		std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		int	flag = -1;

		for(int	i = 0; i < 4; i++)
			if(levels[i].compare(argv[1]) == 0)
			{
				flag = i;
				break;
			}
		switch (flag)
		{
			case (0):
			{
				std::cout<<"["<<levels[0]<<"]\n";
				harl.complain(levels[0]);
			}
			case (1):
			{
				std::cout<<"["<<levels[1]<<"]\n";
				harl.complain(levels[1]);
			}
			case (2):
			{
				std::cout<<"["<<levels[2]<<"]\n";
				harl.complain(levels[2]);
			}
			case (3):
			{
				std::cout<<"["<<levels[3]<<"]\n";
				harl.complain(levels[3]);
				break;
			}
			default:
				std::cout<<"[ Probably complaining about insignificant problems ]\n";
		}
	}
	return (0);
}