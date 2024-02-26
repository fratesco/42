#include "Brain.hpp"

Brain::Brain()
{

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

}
