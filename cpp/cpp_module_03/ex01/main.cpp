#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	ScavTrapA("Gianni");
	ScavTrap	ScavTrapB("Pinotto");

	ScavTrapA.attack("Pinotto");
	ScavTrapB.takeDamage(ScavTrapA.getAttack());
	std::cout<<"Only "<<ScavTrapB.getHp()<<" remaining to "<<ScavTrapB.getName()<<std::endl;
	std::cout<<ScavTrapA.getName()<<" has "<<ScavTrapA.getEnergy()<<" energy points remaining\n";
	return (0);
}