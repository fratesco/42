#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	public:
			Form();
			Form(std::string n, int sign, int exec);
			Form(const Form &src);
			Form &operator=(const Form &src);
			~Form();

			std::string	const	getName();
			bool 				is_Signed();
			int 				getExecGrade();
			int 				getSignGrade();
			void				beSigned(Bureaucrat &src);

			class GradeTooHighException : public std::exception
			{
				public:
					const char *what() const throw();
			};
			class GradeTooLowException : public std::exception
			{
				public:
					const char *what() const throw();
			};
			
	private:
			const std::string name;
			const int sign_grade;
			const int exec_grade;
			bool	is_signed;
			
};

std::ostream &operator<<(std::ostream &out, Form &src);

#endif