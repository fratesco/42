#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
			WrongCat();
			WrongCat(const WrongCat &src);
			virtual WrongCat &operator=(const WrongCat &src);
			virtual ~WrongCat();

			void	makeSound() const;
};

#endif