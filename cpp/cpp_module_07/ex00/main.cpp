#include "template.hpp"
#include <iostream>

int main()
{
	int a = 3;
	int b = 10;


	swap(a,b);
	std::cout<<a<<" "<<b<<std::endl;
	std::cout<<min(a,b)<<std::endl;
	std::cout<<max(a,b)<<std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}
