#include "Character.hpp"

Character::Character()
{
	name= "adfhoidshf";
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
}

Character::Character(const Character &src)
{
	this->name = src.name;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete (inventory[i]);
		if (src.inventory[i])
			this->inventory[i] = src.inventory[i];
		else
			this->inventory[i] = 0;
	}
}

Character *Character::operator=(const Character &src)
{
	this->name = src.name;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete (inventory[i]);
		if (src.inventory[i])
			this->inventory[i] = src.inventory[i];
		else
			this->inventory[i] = 0;
	}
	return (this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete (inventory[i]);
	}
	std::cout<<getName()<<" just died!\n";
}

std::string	const &Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			std::cout<<getName()<<" equipped "<<m->getType()<<std::endl;
			break;
		}
	}
}

void	Character::unequip(int	idx)
{
	
}