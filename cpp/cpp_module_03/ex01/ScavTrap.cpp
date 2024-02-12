#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ScavTrap()
{
	std::cout<<"Unnamed ScavTrap created by default constructor\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	setHP(100);
	setEnergy(50);
	setAttack(20);
	std::cout<<"ScavTrap "<<name<<" created by the constructor\n";
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	*this = src;
	std::cout<<"ScavTrap "<<getName()<<" created by the copy constructor\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	setName(src.name);
	setHP(src.hp);
	setEnergy(src.energy);
	setAttack(src.attack_damage);	
	return (*this);
}
