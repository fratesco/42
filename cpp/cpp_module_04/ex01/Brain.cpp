#include "Brain.hpp"

Brain::Brain()
{
	for(int i = 0; i <= 99; i++)
		this->ideas[i] = "a";
	std::cout<<"*Brainy sounds*\n";
}

Brain::Brain(const Brain &src)
{
	*this = src;
}

Brain &Brain::operator=(const Brain &src)
{
	for(int i = 0; i <= 99; i++)
		this->ideas[i] = src.ideas[i];
	return (*this);
}

void	Brain::setIdea()
{
	this->ideas[0] = "sucate\n";
}

Brain::~Brain()
{
	std::cout<<"*Dies of cringe*\n"<<this->ideas[0];
}
