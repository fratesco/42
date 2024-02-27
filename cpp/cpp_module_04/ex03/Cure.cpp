#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(const Cure &src) : AMateria(src)
{
	type = "cure";
}

Cure	&Cure::operator=(const Cure &src)
{
	this->type = src.type;
	return (*this);
}

Cure::~Cure()
{

}

AMateria	*Cure::clone() const
{
	return (new Cure(*this)); 
}

void	Cure::use(ICharacter &target)
{
	std::cout<<"* heals"<<target.getName()<<"'s wounds *"<<std::endl;
}