#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
			PresidentialPardonForm();
			PresidentialPardonForm(std::string target);
			PresidentialPardonForm(const PresidentialPardonForm &src);
			PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
			~PresidentialPardonForm();
			
			void	action() const;

	private:
			std::string const target;
};

#endif