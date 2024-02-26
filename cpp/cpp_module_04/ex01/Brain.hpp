#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	public:
			Brain();
			Brain(const Brain &src);
			Brain &operator=(const Brain &src);
			~Brain();
			
	private:
			std::string	ideas[100];
			
};

#endif