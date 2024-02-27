#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{

}

Ice::Ice(const Ice &src) : AMateria(src)
{
	type = "ice";
}

Ice	&Ice::operator=(const Ice &src)
{
	this->type = src.type;
	return (*this);
}

Ice::~Ice()
{

}

AMateria	*Ice::clone() const
{
	return (new Ice(*this)); 
}

void	Ice::use(ICharacter &target)
{
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<"*"<<std::endl;
}