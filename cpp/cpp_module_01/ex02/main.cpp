#include <iostream>
#include <string>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout<<"str address: "<<&str<<"\nptr address: "<<stringPTR<<"\nref address: "<<&stringREF<<std::endl<<str<<std::endl<<*stringPTR<<std::endl<<stringREF<<std::endl;
	return (0);
}