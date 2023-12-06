#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called\n";
	this->fixed_point = 0;
}

Fixed::Fixed(Fixed &cpy)
{
	std::cout<<"Copy constructor called\n";
	this->fixed_point = cpy.getRawBits();
}

void Fixed::operator=(Fixed &src)
{
	std::cout<<"Copy assignment operator called\n";
	this->fixed_point = src.getRawBits();
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called\n";
}

int	Fixed::getRawBits()
{
	std::cout<<"getRawBits member function called\n";
	return (fixed_point);
}

void	Fixed::setRawBits(int const	raw)
{
	std::cout<<"setRawBits member function called\n";
	fixed_point = raw;
}