#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contact[8];
		int	num_contact;
		int	current_contact;
	public:
		PhoneBook();
		void	add();
		void	display();
};

#endif