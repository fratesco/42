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
			~Fixed();
			int	getRawBits() const;
			void	setRawBits(int const raw);
			float	toFloat() const;
			int		toInt() const;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed);

#endif