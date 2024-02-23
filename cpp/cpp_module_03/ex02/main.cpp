#include "FragTrap.hpp"

int	main()
{
	FragTrap	FragTrapA("Gianni");
	FragTrap	FragTrapB("Pinotto");

	FragTrapA.attack("Pinotto");
	FragTrapB.takeDamage(FragTrapA.getAttack());
	std::cout<<"Only "<<FragTrapB.getHp()<<" remaining to "<<FragTrapB.getName()<<std::endl;
	std::cout<<FragTrapA.getName()<<" has "<<FragTrapA.getEnergy()<<" energy points remaining\n";
	FragTrapA.highFivesGuys();
	return (0);
}