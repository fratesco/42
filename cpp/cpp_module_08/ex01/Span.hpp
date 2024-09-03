#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <exception>

class Span
{
	public:
			Span(int N);
			Span(const Span &src);
			Span &operator=(const Span &src);
			~Span();
			
			void	addNumber(int num);
			int		shortestSpan();
			int		longestSpan();
			void	addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);

	private:
			Span();
			
			int max_space;
			std::vector<int> vector;
			
};

#endif