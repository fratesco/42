#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	vector = src.vector;
	list = src.list;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		vector = src.vector;
		list = src.list;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::list_add(int value)
{
	
}