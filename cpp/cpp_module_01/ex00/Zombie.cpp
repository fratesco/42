#include "Zombie.hpp"
#include "iostream"

Zombie::~Zombie()
{
	std::cout<<"Zombie "<<name<<"has been destroyed\n";
}

Zombie::Zombie(std::string new_name)
{
	name = new_name;
}

void	Zombie::announce()
{
	std::cout<<name<<": BraiiiiiiinnnzzzZ...\n";
}