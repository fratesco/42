#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
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

	std::cout<<"Form Tests\n";

	Form one;
	std::cout<<one;
	Form two("The great declaration", 100, 20);
	std::cout<<two;
	Form three(two);
	std::cout<<three;
	try
	{
		Form wrong("wrong", 0, 151);
	}
	catch (std::exception &e)
	{
		std::cout<<e.what()<<"\n";
	} 
	Emily.signForm(two);
	Sam.signForm(two);
	one = two;
	std::cout<<one;

	return 0;
}