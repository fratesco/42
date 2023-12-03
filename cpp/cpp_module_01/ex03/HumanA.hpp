#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:

		void	attack();

		HumanA(std::string name, Weapon &weapon);
		~HumanA();

	private:

		Weapon	*weapon;
		std::string	name;
};

#endif