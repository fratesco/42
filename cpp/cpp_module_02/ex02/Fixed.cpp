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
	fixed_point = std::roundf(f * (1 << fractional_bits));
}

void Fixed::operator=(Fixed const &src)
{
	std::cout<<"Copy assignment operator called\n";
	this->fixed_point = src.fixed_point;
}

int	Fixed::operator!=(Fixed const &src) const
{
	if (this->fixed_point != src.fixed_point)
		return (true);
	return (false);
}

int	Fixed::operator==(Fixed const &src) const
{
	if (this->fixed_point == src.fixed_point)
		return (true);
	return (false);
}

int	Fixed::operator>(Fixed const &src) const
{
	if (this->fixed_point > src.fixed_point)
		return (true);
	return (false);
}

int	Fixed::operator<(Fixed const &src) const
{
	if (this->fixed_point < src.fixed_point)
		return (true);
	return (false);
}

int	Fixed::operator>=(Fixed const &src) const
{
	if (this->fixed_point >= src.fixed_point)
		return (true);
	return (false);
}

int	Fixed::operator<=(Fixed const &src) const
{
	if (this->fixed_point <= src.fixed_point)
		return (true);
	return (false);
}

Fixed	Fixed::operator+(Fixed	const &src)
{
	this->fixed_point += src.fixed_point;
	return (*this);
}

Fixed	Fixed::operator-(Fixed	const &src)
{
	this->fixed_point -= src.fixed_point;
	return (*this);
}

Fixed	Fixed::operator*(Fixed	const &src)
{
	this->fixed_point = (this->toFloat() * src.toFloat()) * (1 << this->fractional_bits);
	return (*this);
}

Fixed	Fixed::operator/(Fixed	const &src)
{
	this->fixed_point = (this->toFloat() / src.toFloat()) * (1 << this->fractional_bits);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->fixed_point++;
	return (tmp);
}

Fixed	Fixed::operator++()
{
	this->fixed_point++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->fixed_point--;
	return (tmp);
}

Fixed	Fixed::operator--()
{
	this->fixed_point--;
	return (*this);
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

Fixed	&Fixed::min(Fixed &f, Fixed &s)
{
	if (f > s)
		return (s);
	return (f);
}

Fixed	&Fixed::max(Fixed &f, Fixed &s)
{
	if (f > s)
		return (f);
	return (s);
}

Fixed const	&Fixed::min(Fixed const &f, Fixed const &s)
{
	if (f > s)
		return (s);
	return (f);
}

Fixed const	&Fixed::max(Fixed const &f, Fixed const &s)
{
	if (f > s)
		return (f);
	return (s);
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
	return((float)(fixed_point / (float)(1 << fractional_bits)));
}

int	Fixed::toInt() const
{
	return(fixed_point >> fractional_bits);
}