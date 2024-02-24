#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Unknown")
{
	std::cout<<"An unknown Wronganimal has appeared!\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
	std::cout<<"The copy of an unknown anymal has appeared!\n";
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
	this->type = src.type;
	return (*this);
}

std::string	WrongAnimal::getType() const 
{
	return(type);
}

WrongAnimal::~WrongAnimal()
{
	std::cout<<"The eldritch Wrongbeast returned to their slumber\n";
}

void	WrongAnimal::makeSound() const 
{
	std::cout<<"Wrong and horrific voices repeat silently :'Ph'nglui mglw'nafh Cthulhu R'lyeh wgah'nagl fhtagn'\n";
}