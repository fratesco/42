#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>

class ScalarConverter
{
	public:
			ScalarConverter(const ScalarConverter &src);
			ScalarConverter &operator=(const ScalarConverter &src);
			~ScalarConverter();

			static void convert(std::string str);
			
	private:
			ScalarConverter();
			
};

#endif