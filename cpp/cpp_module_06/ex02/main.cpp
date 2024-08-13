#include "Base.hpp"

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 3; i++)
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		std::cout<<std::endl;
		delete base;
	}
	return 0;
}