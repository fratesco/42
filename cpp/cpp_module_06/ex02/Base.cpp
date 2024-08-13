#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class A;
class B;
class C;

Base::~Base()
{

}

Base *generate()
{
	int random = 1 + (std::rand() % (3 - 1 + 1));
	if (random == 1)
		return new A;
	else if (random == 2)
		return new B;
	else if (random == 3)
		return new C;
	return NULL;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout<<"A\n";
	else if (dynamic_cast<B*>(p))
		std::cout<<"B\n";
	else if (dynamic_cast<C*>(p))
		std::cout<<"C\n";
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout<<"A\n";
	}
	catch(...)
	{
	}
	try
	{
		dynamic_cast<B&>(p);
		std::cout<<"B\n";
	}
	catch(...)
	{
	}
	try
	{
		dynamic_cast<C&>(p);
		std::cout<<"C\n";
	}
	catch(...)
	{
	}
}