#include "Zombie.hpp"

int	main()
{
	Zombie	*tmp = zombieHorde(5, "random");
	delete [] (tmp);
	return (0);
}