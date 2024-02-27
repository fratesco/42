#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{

}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &src)
{
	this->type = src.type;
}

AMateria::~AMateria()
{

}

AMateria &AMateria::operator=(const AMateria &src)
{
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}

std::string	const &AMateria::getType() const
{
	return type;
}

void	AMateria::use(ICharacter &target)
{
	std::cout<<"boh\n";
}