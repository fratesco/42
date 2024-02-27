#include "Animal.hpp"

Animal::Animal() : type("Unknown")
{
	std::cout<<"An unknown animal has appeared!\n";
}

Animal::Animal(const Animal &src)
{
	*this = src;
	std::cout<<"The copy of an unknown anymal has appeared!\n";
}

Animal	&Animal::operator=(const Animal &src)
{
	this->type = src.type;
	return (*this);
}

std::string	Animal::getType() const 
{
	return(type);
}

Animal::~Animal()
{
	std::cout<<"The eldritch beast returned to their slumber\n";
}

void	Animal::makeSound() const 
{
	std::cout<<"Unknown and horrific voices repeat silently :'Ph'nglui mglw'nafh Cthulhu R'lyeh wgah'nagl fhtagn'\n";
}