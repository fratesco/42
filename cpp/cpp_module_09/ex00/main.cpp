#include "BitcoinExchange.hpp"



int main (int argc, char **argv)
{
	if (argc < 2)
		std::cout<<"Input file necessary\n";
	else if (argc > 3)
		std::cout<<"Too many arguments\n";
	else
	{
		BitcoinExchange test;
	}

	return 0;
}