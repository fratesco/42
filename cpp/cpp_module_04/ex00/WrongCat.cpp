#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout<<"A Wrongcat appeared to scratch you\n";
}

WrongCat::WrongCat(const WrongCat &src)
{
	*this = src;
	std::cout<<"The copy of a Wrongcat appeared to scratch you\n";
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	this->type = src.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout<<"The *totally* normal Wrongcat went away\n";
}

void	WrongCat::makeSound() const
{
	std::cout<<"The Wrongcat says 'meeeoooohhw'\n";
}