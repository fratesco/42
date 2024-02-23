#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
			FragTrap();
			FragTrap(std::string name);
			FragTrap(const FragTrap &src);
			FragTrap &operator=(const FragTrap &src);
			~FragTrap();

			void	setName(std::string name);
			void	setHP(unsigned int amount);
			void	setEnergy(unsigned int amount);
			void	setAttack(unsigned int amount);
			int		getAttack();
			int		getEnergy();
			int		getHp();
			void	attack(std::string const &target);
			void	highFivesGuys();
			
	private:
			
};

#endif