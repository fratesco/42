#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <vector>
#include <iostream>

class Character : public ICharacter
{
	protected:
			std::string				name;
			AMateria 				*inventory[4];
			std::vector<AMateria *>	floor;

	public:
			Character();
			Character(std::string name);
			Character(const Character &src);
			Character *operator=(const Character &src);
			~Character();

			std::string const & getName() const;
			void 				equip(AMateria* m);
			void 				unequip(int idx);
			void 				use(int idx, ICharacter& target);
};

#endif