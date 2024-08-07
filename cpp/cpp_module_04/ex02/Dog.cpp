#include "Dog.hpp"

Dog::Dog()
{
	this->brain = new Brain;
	this->type = "Dog";
	std::cout<<"A Dog appeared to bite you\n";
}

Dog::Dog(const Dog &src)
{
	*this = src;
	std::cout<<"The copy of a Dog appeared to bite you\n";
}

Dog &Dog::operator=(const Dog &src)
{
	brain = new Brain;
	*(this->brain) = *(src.brain);
	this->type = src.type;
	return (*this);
}

Dog::~Dog()
{
	delete (this->brain);
	std::cout<<"The *absolutely* normal Dog went away\n";
}

void	Dog::setIdea()
{
	brain->setIdea();
}

void	Dog::makeSound() const 
{
	std::cout<<"The Dog says 'wooooohhf'\n";
}