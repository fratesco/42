#include "easyfind.hpp"

int main() 
{
	std::vector<int> v;
	std::vector<int>::iterator it;

	for (int i = 0; i < 10; ++i) 
		v.push_back(i * i);
	std::cout << "Vector:" << std::endl;
	
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) 
		std::cout << *i << std::endl;
	std::cout << std::endl;

	try
	{
		easyfind(v, -3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		easyfind(v, 2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		easyfind(v, 25);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		easyfind(v, 81);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}