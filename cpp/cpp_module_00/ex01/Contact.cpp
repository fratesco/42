#include "Contact.hpp"

void	aligner(std::string str)
{
		for(int j = ((int)str.size()); j < 9; j++)
			std::cout<<" ";
		if ((int)str.size() >= 10)
			std::cout<<(str.substr(0, 8))<<".";
		else
			std::cout<<str;
		std::cout<<"|";
}

void	Contact::add()
{
	std::cout<<"Type their first name:";
	while (first_name.length() == 0)
		std::cin>>first_name;
	std::cout<<"Type their last name:";
	while (last_name.length() == 0)
		std::cin>>last_name;
	std::cout<<"Type their nickname name:";
	while (nickname.length() == 0)
		std::cin>>nickname;
	std::cout<<"Type their phone number:";
	while (phone_number.length() == 0)
		std::cin>>phone_number;
	std::cout<<"Type their darkest secret:";
	while (darkest_secret.length() == 0)
		std::cin>>darkest_secret;
}

void	Contact::display()
{
	std::cout<<first_name<<std::endl<<last_name<<std::endl<<nickname<<std::endl<<phone_number<<std::endl<<darkest_secret<<std::endl;
}

void	Contact::display_aligned(int i)
{
	for(int j = 0; j < 8; j++)
		std::cout<<" ";
	std::cout<<(i+1)<<"|";
	aligner(first_name);
	aligner(last_name);
	aligner(nickname);
	std::cout<<std::endl;
}

void	Contact::clear()
{
	first_name.clear();
	last_name.clear();
	nickname.clear();
	phone_number.clear();
	darkest_secret.clear();
}