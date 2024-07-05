#include "Brain.hpp"

Brain::Brain()
{
	for(int i = 0; i <= 99; i++)
		this->ideas[i] = "a\n";
	std::cout<<"*Brainy sounds*\n";
}

Brain::Brain(const Brain &src)
{
	for(int i = 0; i <= 99; i++)
			this->ideas[i] = src.ideas[i];
}

Brain &Brain::operator=(const Brain &src)
{
	if (this != &src)
	{
		for(int i = 0; i <= 99; i++)
			this->ideas[i] = src.ideas[i];
	}
	return (*this);
}

void	Brain::setIdea()
{
	this->ideas[0] = "test\n";
}

Brain::~Brain()
{
	std::cout<<"*Dies of cringe* "<<this->ideas[0];
}
