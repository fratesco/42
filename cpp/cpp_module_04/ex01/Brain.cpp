#include "Brain.hpp"

Brain::Brain()
{
	std::cout<<"*Brainy sounds*\n";
}

Brain::Brain(const Brain &src)
{
	*this = src;
}

Brain &Brain::operator=(const Brain &src)
{
	for(int i=0; i <= 99; i++)
		this->ideas[i] = src.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout<<"*Dies of cringe*\n";
}
