#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
			int	fixed_point;
			static const int	fractional_bits = 8;
	public:
			Fixed();
			Fixed(Fixed const &cpy);
			Fixed(int const	i);
			Fixed(float const f);
			void	operator=(Fixed	const &src);
			int	operator>(Fixed	const &src) const;
			int	operator<(Fixed	const &src) const;
			int	operator>=(Fixed	const &src) const;
			int	operator<=(Fixed	const &src) const;
			int	operator==(Fixed	const &src) const;
			int	operator!=(Fixed	const &src) const;
			Fixed	operator+(Fixed	const &src);
			Fixed	operator-(Fixed	const &src);
			Fixed	operator/(Fixed	const &src);
			Fixed	operator*(Fixed	const &src);
			Fixed	operator++();
			Fixed	operator++(int);
			Fixed	operator--();
			Fixed	operator--(int);
			~Fixed();
			static Fixed	&min(Fixed &f, Fixed &s);
			static Fixed	&max(Fixed &f, Fixed &s);
			static Fixed const	&min(Fixed const &f, Fixed const &s);
			static Fixed const	&max(Fixed const &f, Fixed const &s);
			int	getRawBits() const;
			void	setRawBits(int const raw);
			float	toFloat() const;
			int		toInt() const;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed);

#endif