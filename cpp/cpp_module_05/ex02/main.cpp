#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
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

	std::cout<<"AForms Tests\n";

	ShrubberyCreationForm tree("forest");
	std::cout << tree;
	RobotomyRequestForm robo("srapuano");
	std::cout << robo;
	PresidentialPardonForm pardon("srapuano");
	std::cout << pardon;
	Emily.signForm(tree);
	Robert.signForm(tree);
	Tim.signForm(robo);
	Emily.executeForm(tree);
	Tim.executeForm(tree);
	Robert.executeForm(pardon);
	Sam.signForm(pardon);
	Robert.executeForm(pardon);
	Robert.executeForm(robo);
	return 0;
}