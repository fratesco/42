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
	list.push_back(value);
}

void PmergeMe::vector_add(int value)
{
	vector.push_back(value);
}

uint64_t PmergeMe::get_vector_time()
{
	return time_vector;
}

uint64_t PmergeMe::get_list_time()
{
	return time_list;
}

std::vector<int> PmergeMe::list_sorter()
{
	
}