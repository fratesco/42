#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
			ScavTrap();
			ScavTrap(std::string name);
			ScavTrap(const ScavTrap &src);
			ScavTrap &operator=(const ScavTrap &src);
			~ScavTrap();

			void	setName(std::string name);
			void	setHP(unsigned int amount);
			void	setEnergy(unsigned int amount);
			void	setAttack(unsigned int amount);
			int		getAttack();
			int		getEnergy();
			int		getHp();
			void	attack(std::string const &target);
			//void	takeDamage(unsigned int amount);
			void	guardGate();
			
	private:
			
};

#endif