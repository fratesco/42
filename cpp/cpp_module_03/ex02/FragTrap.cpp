#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout<<"Unnamed FragTrap created by default constructor\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	setHP(100);
	setEnergy(100);
	setAttack(30);
	std::cout<<"FragTrap "<<name<<" created by the constructor\n";
}

FragTrap::FragTrap(const FragTrap &src)
{
	*this = src;
	std::cout<<"FragTrap "<<getName()<<" created by the copy constructor\n";
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	setName(src.name);
	setHP(src.hp);
	setEnergy(src.energy);
	setAttack(src.attack_damage);	
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout<<"FragTrap "<<name<<" became a pile of scraps.\n";
	return ;
}

void	FragTrap::setName(std::string name)
{
	this->name = name;
}

void	FragTrap::setHP(unsigned int amount)
{
	this->hp = amount;
}

void	FragTrap::setEnergy(unsigned int amount)
{
	this->energy = amount;
}

void	FragTrap::setAttack(unsigned int amount)
{
	this->attack_damage = amount;
}


int		FragTrap::getAttack()
{
	return(attack_damage);
}

int		FragTrap::getEnergy()
{
	return(energy);
}

int		FragTrap::getHp()
{
	return(hp);
}
void	FragTrap::attack(std::string const &target)
{
	if ((hp > 0) && (energy > 0))
		std::cout<<"FragTrap "<<name<<" dealt "<<attack_damage<<" points of damage to "<<target<<"!\n";
	else if (hp <= 0)
		std::cout<<"FragTrap "<<name<<" is broken and need repairing.\n";
	else if (energy <= 0)
		std::cout<<"FragTrap "<<name<<" is out of energy.\n";
	energy--;
}

void	FragTrap::highFivesGuys()
{
	std::cout<<name<<": 'Let's highfive guys!'\n";
}

