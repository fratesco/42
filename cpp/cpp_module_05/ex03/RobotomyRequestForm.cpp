#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("undefined")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string targ) :  AForm("RobotomyRequestForm", 72, 45), target(targ)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :  AForm("RobotomyRequestForm", 72, 45), target(src.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	(void)src;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::action() const
{
	srand(time(NULL));
	std::cout<<"Zzzzzzzzz Zzzzzzzzzzzzzzzzzzzz \n";
	if (rand() % 2)
		std::cout<<target<<" has been robotomized successfully\n";
	else
		std::cout<<"OH NO! the robotomy failed\n";
}