#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
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

	std::cout<<"AForm Tests\n";


	return 0;
}