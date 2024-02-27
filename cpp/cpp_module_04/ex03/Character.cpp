#include "Character.hpp"
#include "AMateria.hpp"

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
	for (int i = 0; i < floor.size(); i++)
		delete(floor[i]);
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
	if (idx > 0 && idx < 4 && inventory[idx])
	{
		std::cout<<getName()<<" dropped "<<inventory[idx]->getType()<<"on the floor"<<std::endl;
		floor.push_back(inventory[idx]);
		inventory[idx] = 0;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}