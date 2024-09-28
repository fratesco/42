#include "MutantStack.hpp"

int main(void) 
{
    MutantStack<int> mstack;
    mstack.push(7);
    mstack.push(21);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl<<std::endl;
    mstack.push(3);
    mstack.push(9);
    mstack.push(11);

    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
	std::cout<<std::endl;
    MutantStack<int> s(mstack);
    MutantStack<int>::iterator it1;
    for (it1 = s.begin(); it1 != s.end(); ++it1)
    {
        std::cout << *it1 << std::endl;
    }

    return 0;
}