#include "PhoneBook.hpp"

int	main()
{
	PhoneBook		book;
	std::string		tmp;
	while (1)
	{
		tmp.clear();
		std::cout<<"Enter one of the following commands: ADD, SEARCH, EXIT.\n>: ";
		while (tmp.empty() && std::cin)
			getline(std::cin, tmp);
		if (!std::cin)
			break;
		if (tmp.compare("ADD") == 0)
			book.add();
		else if (tmp.compare("SEARCH") == 0)
			book.display();
		else if (tmp.compare("EXIT") == 0)
			break ;
	}
	return (0);
}