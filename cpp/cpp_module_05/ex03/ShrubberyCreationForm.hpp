#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
			ShrubberyCreationForm();
			ShrubberyCreationForm(std::string targ);
			ShrubberyCreationForm(const ShrubberyCreationForm &src);
			ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
			~ShrubberyCreationForm();

			void	action() const;
			
	private:
			std::string const target;
};

#endif


