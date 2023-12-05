#include "Harl.hpp"

void	Harl::debug()
{
	std::cout<<"Debuuug message!\n";
}

void	Harl::info()
{
	std::cout<<"Wanna have some cool info?\n";
}

void	Harl::warning()
{
	std::cout<<"Warning: I am warning you\n";
}

void	Harl::error()
{
	std::cout<<"There was an error, oopsies\n";
}

void	Harl::complain(std::string level)
{
	void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		!levels[i].compare(level) ? ((this->*functions[i])()) : void();
}