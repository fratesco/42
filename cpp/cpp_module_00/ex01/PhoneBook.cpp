#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	num_contact = 0;
	current_contact = 0;
}

void PhoneBook::add()
{
	if (num_contact > 7)
	{
		if (current_contact == 8)
			current_contact = 0;
		std::cout<<"Maximum number of contacts reached; Overwriting the oldest one\n";
		contact[current_contact].clear();
	}
	else if (num_contact < 8)
		num_contact++;
	contact[current_contact++].add();
	std::cout<<"Successfully added the contact\n";
}

void PhoneBook::display()
{
	for(int j = 0; j < num_contact; j++)
		contact[j].display_aligned(j);
	while(1)
	{
		std::cout<<"Insert the index of the contact you want to display: ";
		std::string tmp;
		getline(std::cin, tmp);
		if (tmp.empty() || tmp.size() > 1)
		{
			std::cout<<"Null or out of range index\n";
			break ;
		}
		int cond = 1;
		for(int	i = 0; !tmp.empty() && tmp[i]; i++)
		{
			if (!isdigit(tmp[i]) || tmp[i] == '0')
			{
				std::cout<<"Not a valid index\n";
				cond = 0;
				break ;
			}
			if ((tmp[i] - 48) > num_contact)
			{
				std::cout<<"That index has no contact\n";
				cond = 0;
				break;
			}
		}
		if (cond)
			contact[tmp[0] - 49].display();
		break ;
	}
}