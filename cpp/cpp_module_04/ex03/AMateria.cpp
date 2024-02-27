#include "AMateria.hpp"

AMateria::AMateria()
{

}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
}

AMateria::~AMateria()
{
	
}

std::string	const &AMateria::getType() const
{
	return (type);
}

