#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	public:
			AForm();
			AForm(std::string n, int sign, int exec);
			AForm(const AForm &src);
			AForm &operator=(const AForm &src);
			~AForm();

			std::string	const	getName() const;
			bool const			is_Signed();
			int const			getExecGrade();
			int const			getSignGrade();
			void				beSigned(Bureaucrat &src);
			void				execute(Bureaucrat const & executor) const;
			virtual void		action() const  = 0;

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
			
			class NotSigned : public std::exception
			{
				public:
					const char *what() const throw();
			};

	private:
			const std::string name;
			bool	is_signed;
			const int sign_grade;
			const int exec_grade;
			
};

std::ostream &operator<<(std::ostream &out, AForm &src);

#endif