#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	public:

		Zombie(std::string new_name);
		~Zombie();

		void announce( void );

	private:

		std::string name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif