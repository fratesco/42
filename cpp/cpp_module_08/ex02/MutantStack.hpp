#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T>>
{
	public:
			MutantStack() {};
			MutantStack(const MutantStack &src) {*this = src;};
			MutantStack &operator=(const MutantStack &src) {this->c = src.c; return *this;};
			~MutantStack() {this->c.clear();};

			typedef typename std::stack<T>::container_type::iterator iterator;

			iterator begin() {return this->c.begin();};
			iterator end() {return this->c.end();};
			
	private:
			
};

#endif