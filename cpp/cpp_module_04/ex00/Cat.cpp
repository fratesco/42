#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout<<"A cat appeared to scratch you\n";
}

Cat::Cat(const Cat &src)
{
	*this = src;
	std::cout<<"The copy of a cat appeared to scratch you\n";
}

Cat &Cat::operator=(const Cat &src)
{
	this->type = src.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout<<"The *totally* normal cat went away\n";
}

void	Cat::makeSound() const
{
	std::cout<<"The cat says 'meeeoooohhw'\n";
}