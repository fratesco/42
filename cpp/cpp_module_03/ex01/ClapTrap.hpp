#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:
			ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap &src);
			ClapTrap &operator=(const ClapTrap &src);
			~ClapTrap();
			
			void		attack(const std::string &target);
			void		takeDamage(unsigned	int amount);
			void		beRepaired(unsigned int amount);
			std::string	getName();
			
	protected:
			std::string	name;
			int	hp;
			int	energy;
			int	attack_damage;
			
};

#endif