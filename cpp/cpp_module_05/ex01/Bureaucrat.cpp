#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Undefined") , grade(1)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name)
{
	*this=src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	this->grade = src.grade;
	return *this; 
}

Bureaucrat::Bureaucrat(int grade, std::string name) : name(name)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
		this->grade = grade;
	}
	catch (std::exception &e)
	{
		std::cerr<<e.what()<<std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
}

std::string const Bureaucrat::getName()
{
	return name;
}

int	Bureaucrat::getGrade()
{
	return grade;
}

void	Bureaucrat::increaseGrade()
{
	try
	{
		if (grade == 1)
			throw GradeTooHighException();
		grade--;
	}
	catch(GradeTooHighException &e)
	{
		std::cerr<<e.what()<<std::endl;
	}
}

void	Bureaucrat::decreaseGrade()
{
	try
	{
		if (grade == 150)
			throw GradeTooLowException();
		grade++;
	}
	catch(GradeTooLowException &e)
	{
		std::cerr<<e.what()<<std::endl;
	}
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(std::exception &e)
	{
		std::cout<<getName()<<" couldn't sign "<<form.getName()<<" because "<<e.what()<<std::endl;
		return ;
	}
	std::cout<<getName()<<" has signed "<<form.getName()<<"\n";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &src)
{
	out<<src.getName()<<", bureaucrat grade "<<src.getGrade()<<std::endl;
	return out;
}
