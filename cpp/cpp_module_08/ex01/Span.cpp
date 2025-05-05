#include "Span.hpp"

Span::Span()
{
}

Span::Span(int N) : max_space(N)
{
}

Span::Span(const Span &src)
{
	*this = src;
}

Span &Span::operator=(const Span &src)
{
	max_space = src.max_space;
	vector = src.vector;
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int num)
{
	if (vector.size() == max_space)
		throw std::out_of_range("The vector is already full\n");
	vector.push_back(num);
}

int Span::shortestSpan()
{
	if (vector.size() < 2)
		throw std::out_of_range("Not enought elements in the vector\n");

	std::vector<int>::iterator it = vector.begin();
	int lowest = abs(*(it) - *(it + 1));

	for (unsigned long int i = 0; i < max_space; i++)
	{
		for (unsigned long int j = i + 1; j + i < max_space; j++)
		{
			int value = abs(*(it + i) - *(it + j));
			if (lowest > value)
				lowest = value;
		}
	}
	return lowest;
}

int Span::longestSpan()
{
	if (vector.size() < 2)
		throw std::out_of_range("Not enought elements in the vector\n");

	int highest = 0;
	std::vector<int>::iterator it = vector.begin();

	for (unsigned long int i = 0; i < max_space; i++)
	{
		for (unsigned long int j = i + 1; j + i < max_space; j++)
		{
			int value = abs(*(it + i) - *(it + j));
			if (highest < value)
				highest = value;
		}
	}
	return highest;
}

void Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (std::distance(start, end) + vector.size() > max_space)
		throw std::out_of_range("Not enought space in the vector\n");
	vector.insert(vector.end(), start, end);
}
