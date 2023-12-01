#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string darkest_secret;
	public:
		void	add();
		void	display();
		void	display_aligned(int i);
		void	clear();

};

#endif