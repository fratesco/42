#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
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

ScavTrap::~ScavTrap()
{
	std::cout<<"ScavTrap "<<name<<" became a pile of scraps.\n";
	return ;
}

void	ScavTrap::setName(std::string name)
{
	this->name = name;
}

void	ScavTrap::setHP(unsigned int amount)
{
	this->hp = amount;
}

void	ScavTrap::setEnergy(unsigned int amount)
{
	this->energy = amount;
}

void	ScavTrap::setAttack(unsigned int amount)
{
	this->attack_damage = amount;
}


int		ScavTrap::getAttack()
{
	return(attack_damage);
}

int		ScavTrap::getEnergy()
{
	return(energy);
}

int		ScavTrap::getHp()
{
	return(hp);
}
void	ScavTrap::attack(std::string const &target)
{
	if ((hp > 0) && (energy > 0))
		std::cout<<"ScavTrap "<<name<<" dealt "<<attack_damage<<" points of damage to "<<target<<"!\n";
	else if (hp <= 0)
		std::cout<<"ScavTrap "<<name<<" is broken and need repairing.\n";
	else if (energy <= 0)
		std::cout<<"ScavTrap "<<name<<" is out of energy.\n";
	if ((hp > 0) && (energy > 0))
	energy--;
}
//void	ScavTrap::takeDamage(unsigned int amount)
//{
//
//}
void	ScavTrap::guardGate()
{
	std::cout<<"Scavtrap "<<name<<" entered gate keeper mode\n";
}
