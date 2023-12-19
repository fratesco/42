#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hp = 10;
	this->energy = 10;
	this->attack_damage = 0;

	std::cout<<"ClapTrap "<<name<<" created by the default constructor\n";
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
	std::cout<<"ClapTrap "<<name<<" created by the copy constructor\n";
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
	this->name = src.name;
	this->hp = src.hp;
	this->energy = src.energy;
	this->attack_damage = src.attack_damage;	
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout<<"ClapTrap "<<name<<" became a pile of scraps.\n";
	return ;
}

void	ClapTrap::attack(const std::string &target)
{
	if ((hp > 0) && (energy > 0))
		std::cout<<"ClapTrap "<<name<<" dealt "<<attack_damage<<" points of damage to "<<target<<"!\n";
	else if (hp <= 0)
		std::cout<<"ClapTrap "<<name<<" is broken and need repairing.\n";
	else if (energy <= 0)
		std::cout<<"ClapTrap "<<name<<" is out of energy.\n";
	energy--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount <= hp)
		hp -= amount;
	else if (amount > hp)
		hp = 0;
	std::cout<<"ClapTrap "<<name<<" took "<<amount<<" points of damage and its health is reduced to "<<hp<<"\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energy <= 0)
		return ((void)(std::cout<<"ClapTrap "<<name<<" is out of energy.\n"));
	energy--;
	hp += amount;
	std::cout<<"ClapTrap "<<name<<" got repaired and restored "<<amount<<" health points!\n";
}
