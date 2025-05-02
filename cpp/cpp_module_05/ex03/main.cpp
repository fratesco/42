#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
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

	Intern intern;

	try
	{
		AForm *form = intern.makeForm("random", "random");
		(void)form;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		AForm *form = intern.makeForm("presidential pardon", "myself");
		Robert.executeForm(*form);
		Robert.signForm(*form);
		Robert.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}