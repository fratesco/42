#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	public:

		Zombie(std::string new_name);
		Zombie();
		~Zombie();

		void	announce();
		void	setName(std::string name);

	private:

		std::string name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif