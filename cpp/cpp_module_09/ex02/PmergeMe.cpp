#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	deque = src.deque;
	list = src.list;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		deque = src.deque;
		list = src.list;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

std::deque<int> &PmergeMe::get_deque()
{
	return deque;
}

std::list<int> &PmergeMe::get_list()
{
	return list;
}

void PmergeMe::list_add(int value)
{
	list.push_back(value);
}

void PmergeMe::vector_add(int value)
{
	deque.push_back(value);
}

uint64_t PmergeMe::get_vector_time()
{
	return time_deque;
}
uint64_t PmergeMe::get_list_time()
{
	return time_list;
}

void PmergeMe::list_sorter(std::list<int> &l)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);

	if (l.size() <= 1)
		return;
	std::list<int> left, right;
	std::list<int>::iterator it = l.begin();
	for (size_t i = 0; i < l.size() / 2; ++i)
		++it;
	left.splice(left.begin(), l, l.begin(), it);
	right.splice(right.begin(), l);
	list_sorter(left);
	list_sorter(right);
	list.clear();
	std::list<int>::iterator leftIt = left.begin();
	std::list<int>::iterator rightIt = right.begin();
	while (leftIt != left.end() && rightIt != right.end()) {
		if (*leftIt <= *rightIt) {
			l.push_back(*leftIt);
			++leftIt;
		}
		else {
			l.push_back(*rightIt);
			++rightIt;
		}
	}
	while (leftIt != left.end()) {
		l.push_back(*leftIt);
		++leftIt;
}
	while (rightIt != right.end()) {
		l.push_back(*rightIt);
		++rightIt;
	}
	
	gettimeofday(&end, NULL);

	this->time_list = end.tv_usec - start.tv_usec;
}

void	PmergeMe::deque_sorter(std::deque<int> &d)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);

    if (d.size() <= 1)
        return;

    std::deque<int> left, right;
    size_t mid = d.size() / 2;

    for (size_t i = 0; i < mid; ++i)
        left.push_back(d[i]);
    for (size_t i = mid; i < d.size(); ++i)
        right.push_back(d[i]);

    deque_sorter(left);
    deque_sorter(right);

    d.clear();
    size_t leftIdx = 0, rightIdx = 0;

    while (leftIdx < left.size() && rightIdx < right.size()) {
        if (left[leftIdx] <= right[rightIdx]) {
            d.push_back(left[leftIdx]);
            ++leftIdx;
        } else {
            d.push_back(right[rightIdx]);
            ++rightIdx;
        }
    }

    while (leftIdx < left.size()) {
        d.push_back(left[leftIdx]);
        ++leftIdx;
    }
    while (rightIdx < right.size()) {
        d.push_back(right[rightIdx]);
        ++rightIdx;
    }

	gettimeofday(&end, NULL);

	this->time_deque = end.tv_usec - start.tv_usec;
}
