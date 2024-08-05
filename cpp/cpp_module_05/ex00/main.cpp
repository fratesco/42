#include <iostream>
#include "Bureaucrat.hpp"
#include <unistd.h>

int main()
{
	Bureaucrat Sam(21, "SAm");
	std::cout << Sam;
	Bureaucrat Tim(42, "TIM");
	std::cout << Tim;
	Bureaucrat Robert(1, "ROb");
	std::cout << Robert;
	Bureaucrat Emily(150, "emily");
	std::cout << Emily << std::endl;

	std::cout << "Try to increase Rob's grade: " << std::endl;
	Robert.increaseGrade();
	std::cout << Robert;
	std::cout << std::endl << "Try to decrease Emily's grade: " << std::endl;
	Emily.decreaseGrade();
	std::cout << Emily << std::endl;
	std::cout << "Try to create a bureaucrat with invalid grade:" << std::endl;
	Bureaucrat Zero(0, "zero");
	Bureaucrat Million(1000000, "million");

	return 0;
}