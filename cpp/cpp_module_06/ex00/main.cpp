#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			ScalarConverter::convert(argv[i]);
			std::cout<<std::endl;
		}
	}
	return 0;
}