#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Undefined"), is_signed(false), sign_grade(150), exec_grade(1)
{
}

AForm::AForm(std::string n, int sign, int exec) : name(n), sign_grade(sign), exec_grade(exec), is_signed(false)
{
	if (sign > 150 || exec > 150)
		throw GradeTooLowException();
	if (sign < 1 || exec < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &src) : name(src.name), sign_grade(src.sign_grade), exec_grade(src.exec_grade), is_signed(src.is_signed)
{
}

AForm &AForm::operator=(const AForm &src)
{
	this->is_signed = src.is_signed;
	return *this;
}

AForm::~AForm()
{
}

std::string const AForm::getName() const 
{
	return name;
}

bool const AForm::is_Signed()
{
	return is_signed;
}

int const AForm::getExecGrade()
{
	return exec_grade;
}

int const AForm::getSignGrade()
{
	return sign_grade;
}

void AForm::beSigned(Bureaucrat &src)
{
	if (src.getGrade() > getSignGrade())
		throw GradeTooLowException();
	else
		is_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > exec_grade)
		throw GradeTooLowException();
	if (!is_signed)
		throw NotSigned();
	action();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "The grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "The grade is too low";
}

const char *AForm::NotSigned::what() const throw()
{
	return "The form is not signed";
}

std::ostream &operator<<(std::ostream &out, AForm &src)
{
	std::cout<<"The AForm: "<<src.getName()<<" requires grade "<<src.getSignGrade()<< " to be signed and ";
	std::cout<<"grade "<<src.getExecGrade()<< " to be executed \n";
	if (src.is_Signed())
		std::cout<<src.getName()<<" is signed\n";
	if (!src.is_Signed())
		std::cout<<src.getName()<<" is not signed\n";
	return out;
}
