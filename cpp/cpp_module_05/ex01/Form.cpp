#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Undefined"), is_signed(false), sign_grade(150), exec_grade(1)
{
}

Form::Form(std::string n, int sign, int exec) : name(n), sign_grade(sign), exec_grade(exec), is_signed(false)
{
	if (sign > 150 || exec > 150)
		throw GradeTooLowException();
	if (sign < 1 || exec < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &src) : name(src.name), sign_grade(src.sign_grade), exec_grade(src.exec_grade), is_signed(src.is_signed)
{
}

Form &Form::operator=(const Form &src)
{
	this->is_signed = src.is_signed;
	return *this;
}

Form::~Form()
{
}

std::string const Form::getName()
{
	return name;
}

bool const Form::is_Signed()
{
	return is_signed;
}

int const Form::getExecGrade()
{
	return exec_grade;
}

int const Form::getSignGrade()
{
	return sign_grade;
}

void Form::beSigned(Bureaucrat &src)
{
	if (src.getGrade() > getSignGrade())
		throw GradeTooLowException();
	else
		is_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "The grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "The grade is too low";
}

std::ostream &operator<<(std::ostream &out, Form &src)
{
	std::cout<<"The Form: "<<src.getName()<<" requires grade "<<src.getSignGrade()<< " to be signed and ";
	std::cout<<"grade "<<src.getExecGrade()<< " to be executed \n";
	if (src.is_Signed())
		std::cout<<src.getName()<<" is signed\n";
	if (!src.is_Signed())
		std::cout<<src.getName()<<" is not signed\n";
	return out;
}
