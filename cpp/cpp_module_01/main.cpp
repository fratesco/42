#include "Zombie.hpp"

int	main()
{
	Zombie *zombie = newZombie("chad");
	randomChump("idiot");
	zombie->announce();
	delete(zombie);
	return (0);
}