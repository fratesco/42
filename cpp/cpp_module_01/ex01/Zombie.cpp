#include "Zombie.hpp"
#include "iostream"

Zombie::~Zombie()
{
	std::cout<<"Zombie "<<name<<" has been destroyed\n";
}

Zombie::Zombie(std::string new_name)
{
	name = new_name;
}

Zombie::Zombie()
{
	name = "\0";
}

void	Zombie::setName(std::string name)
{
	this->name = name;
	announce();
}

void	Zombie::announce()
{
	std::cout<<name<<": BraiiiiiiinnnzzzZ...\n";
}