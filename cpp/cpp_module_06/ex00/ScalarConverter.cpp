#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

int ScalarConverter::stoint(const std::string& str)
	{
		const char *sptr = str.c_str();
		char *end;
		errno = 0;
		long result = std::strtol(sptr, &end, 10);

		if (sptr == end)
			throw std::invalid_argument("invalid stoi argument");
		if (errno == ERANGE)
			throw std::out_of_range("stoi argument out of range");

		return ((int)result);
	}

float ScalarConverter::stofloat(const std::string& str)
	{
		const char *ptr = str.data();
		errno = 0;
		char *end;
		float result = std::strtof(ptr, &end);

		if (ptr == end)
			throw std::invalid_argument("invalid stod argument");
		if (errno == ERANGE)
			throw std::out_of_range("stof argument out of range");
		return result;
	}

double ScalarConverter::stodouble(const std::string& str)
	{
		const char *ptr = str.data();
		errno = 0;
		char *end;
		double result = std::strtod(ptr, &end);

		if (ptr == end)
			throw std::invalid_argument("invalid stod argument");
		if (errno == ERANGE)
			throw std::out_of_range("stod argument out of range");
		return result;
	}

void	ScalarConverter::convert(std::string str)
{
	try
	{
		int intval = stoint(str);
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
		float fval = stofloat(str);
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
		double dval = stodouble(str);
		std::cout<<"double: "<<dval<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout<<"double: impossible\n";
	}	
}