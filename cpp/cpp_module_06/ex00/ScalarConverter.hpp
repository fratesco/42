#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cerrno>
#include <cstdlib>

class ScalarConverter
{
	public:
			ScalarConverter(const ScalarConverter &src);
			ScalarConverter &operator=(const ScalarConverter &src);
			~ScalarConverter();

			static void convert(std::string str);
			static int stoint(const std::string& str);
			static float stofloat(const std::string& str);
			static double stodouble(const std::string& str);
			
	private:
			ScalarConverter();
			
};

#endif