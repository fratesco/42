#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

 
class Bureaucrat
{
	public:
			Bureaucrat();
			Bureaucrat(int grade, std::string name);
			Bureaucrat(const Bureaucrat &src);
			Bureaucrat &operator=(const Bureaucrat &src);
			~Bureaucrat();

			std::string	const getName();
			int	getGrade();
			void	increaseGrade();
			void	decreaseGrade();

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
			std::string const name;
			int grade;
			
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &src);

#endif