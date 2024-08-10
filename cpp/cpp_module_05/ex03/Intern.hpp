#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public:
			Intern();
			Intern(const Intern &src);
			Intern &operator=(const Intern &src);
			~Intern();
			
			AForm *creation(std::string targ);
			AForm *pardon(std::string targ);
			AForm *robotomy(std::string targ);
			AForm *makeForm(std::string name, std::string target);

			class InvalidForm : public std::exception
			{
				public:
						const char *what() const throw();
			};

	private:
			
};

#endif