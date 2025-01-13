#include "RPN.hpp"

int main(int argc, char** argv)
{
	int	i = 0;
	RPN	rpn;
	if (argc != 2)
	{
		std::cerr<<"Invalid number of arguments!"<<std::endl;
		return 1;
	}
	try
	{
		while (argv[1][i])
		{
			while (std::isspace(argv[1][i]))
				i++;
			if (argv[1][i] == ADD)
				rpn.addiction();
			else if (argv[1][i] == SUB)
				rpn.subtraction();
			else if (argv[1][i] == DIV)
				rpn.division();
			else if (argv[1][i] == MUL)
				rpn.multiplication();
			else if (argv[1][i] <= '9' && argv[1][i] >= '0')
				rpn.push((int)argv[1][i] - 48);
			else
				throw std::invalid_argument("ERROR");
			i++;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	
	std::cout<<rpn.pop()<<std::endl;

	return 0;
	
}