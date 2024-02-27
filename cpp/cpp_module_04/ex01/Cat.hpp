#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
			Cat();
			Cat(const Cat &src);
			Cat &operator=(const Cat &src);
			~Cat();
			
			void	makeSound() const;
	private:
			Brain	*brain;
};

#endif