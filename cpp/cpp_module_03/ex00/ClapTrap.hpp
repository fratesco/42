#include <iostream>
#include <string>

class ClapTrap
{
	public:
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap &src);
			ClapTrap &operator=(const ClapTrap &src);
			~ClapTrap();
			
			void	attack(const std::string &target);
			void	takeDamage(unsigned	int amount);
			void	beRepaired(unsigned int amount);
			
	private:
			std::string	name;
			int	hp;
			int	energy;
			int	attack_damage;
			
};