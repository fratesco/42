#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
			int	fixed_point;
			static const int	fractional_bits = 8;
	public:
			Fixed();
			Fixed(Fixed &cpy);
			void	operator=(Fixed	&src);
			~Fixed();
			int	getRawBits();
			void	setRawBits(int const raw);
};

#endif