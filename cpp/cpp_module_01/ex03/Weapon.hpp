#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	public:

		const std::string	&getType();
		void	setType(std::string new_type);

		Weapon(std::string	type);
		~Weapon();

	private:

		std::string	type;

};

#endif