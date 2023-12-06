#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called\n";
	this->fixed_point = 0;
}

Fixed::Fixed(Fixed const &cpy)
{
	std::cout<<"Copy constructor called\n";
	*this = cpy;
}

Fixed::Fixed(int const i)
{
	std::cout<<"Int constructor called\n";
	fixed_point = i << fractional_bits;
}

Fixed::Fixed(float const f)
{
	std::cout<<"Float constructor called\n";
	fixed_point = roundf(f * (1 << fractional_bits));
}

void Fixed::operator=(Fixed const &src)
{
	std::cout<<"Copy assignment operator called\n";
	this->fixed_point = src.fixed_point;
}

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed)
{
	os<<fixed.toFloat();
	return (os);
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called\n";
}

int	Fixed::getRawBits() const
{
	std::cout<<"getRawBits member function called\n";
	return (fixed_point);
}

void	Fixed::setRawBits(int const	raw)
{
	std::cout<<"setRawBits member function called\n";
	fixed_point = raw;
}

float	Fixed::toFloat() const
{
	return((fixed_point / (1 << fractional_bits)));
}

int	Fixed::toInt() const
{
	return(fixed_point >> fractional_bits);
}