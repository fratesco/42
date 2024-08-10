#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
			RobotomyRequestForm();
			RobotomyRequestForm(std::string targ);
			RobotomyRequestForm(const RobotomyRequestForm &src);
			RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
			~RobotomyRequestForm();

			void	action() const;
			
	private:
			std::string const target;
			
};

#endif