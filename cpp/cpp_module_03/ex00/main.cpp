#include "ClapTrap.hpp"

int	main()
{
	ClapTrap one("bob");
	ClapTrap two(one);
	ClapTrap three("test");

	three = two;
	three.attack("bob");
	one.takeDamage(0);
	one.beRepaired(1);
	one.beRepaired(1);
	one.beRepaired(1);
	one.beRepaired(1);
	one.beRepaired(1);
	one.beRepaired(1);
	one.beRepaired(1);
	one.beRepaired(1);
	one.beRepaired(1);
	one.beRepaired(10);
	one.attack("test");
	return (0);
}