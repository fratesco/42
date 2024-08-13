#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void	ScalarConverter::convert(std::string str)
{
	try
	{
		int intval = std::stoi(str);
		if (intval < 32 || intval > 127)
			std::cout<<"char: Non displayable\nint: "<<intval<<std::endl;
		else
			std::cout<<"char: "<<(char)(intval)<<"\nint: "<<intval<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout<<"char: impossible\nint: impossible\n";
	}
	try
	{
		float fval = std::stof(str);
		if ((fval - ((int)fval)) == 0)
			std::cout<<"float: "<<fval<<".0f\n";
		else
			std::cout<<"float: "<<fval<<"f\n";
	}
	catch(const std::exception& e)
	{
		std::cout<<"float: impossible\n";
	}
	try
	{
		double dval = std::stod(str);
		std::cout<<"double: "<<dval<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout<<"double: impossible\n";
	}	
}