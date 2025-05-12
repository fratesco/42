#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <deque>
#include <list>
#include <string>
#include <vector>
#include <sys/time.h>
#include <stdlib.h>
#include <cctype>
#include <stdint.h>
#include <cerrno>


class PmergeMe
{
	public:
			PmergeMe();
			PmergeMe(const PmergeMe &src);
			PmergeMe &operator=(const PmergeMe &src);
			~PmergeMe();

			void list_add(int value);
			void vector_add(int value);
			uint64_t	get_list_time();
			uint64_t	get_vector_time();
			void list_sorter(std::list<int> &l);
			void deque_sorter(std::deque<int> &d);
			std::deque<int> &get_deque();
			std::list<int> &get_list();

			
	private:
			uint64_t time_list;
			uint64_t time_deque;
			std::list<int>	 list;
			std::deque<int> deque;
};

#endif