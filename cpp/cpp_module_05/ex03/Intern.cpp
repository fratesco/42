#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::creation(std::string targ)
{
	return new ShrubberyCreationForm(targ);
}

AForm *Intern::pardon(std::string targ)
{
	return new PresidentialPardonForm(targ);
}

AForm *Intern::robotomy(std::string targ)
{
	return new RobotomyRequestForm(targ);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	AForm *(Intern::*method [3])(std::string targ) = {&Intern::creation, &Intern::pardon, &Intern::robotomy};

	for (int i = 0 ; i < 3; i++)
	{
		if (name == forms[i])
		{
			AForm *form = (this->*method[i])(target);
			std::cout<<"The intern createad the form "<<form->getName()<<std::endl;
			return form;
		}
	}
	throw InvalidForm();
	return NULL;
}

const char *Intern::InvalidForm::what() const throw()
{
	return "The form template does not exist";
}
