#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <list>
#include <string>
#include <time.h>

class PmergeMe
{
	public:
			PmergeMe();
			PmergeMe(const PmergeMe &src);
			PmergeMe &operator=(const PmergeMe &src);
			~PmergeMe();

			void list_add(int value);
			void vector_add(int value);
			std::vector<int> list_sorter();
			std::vector<int> vector_sorter();
			uint64_t	get_vector_time();
			uint64_t	get_list_time();

			
	private:
			uint64_t time_list;
			uint64_t time_vector;
			std::vector<int> vector;
			std::list<int>	 list;
};

#endif