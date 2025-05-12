#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <exception>

#define ADD '+'
#define SUB '-'
#define DIV '/'
#define MUL '*'

class RPN
{
	public:
			RPN();
			RPN(const RPN &src);
			RPN &operator=(const RPN &src);
			~RPN();

			void	push(int a);
			int		pop();
			int 	addiction();
			int		subtraction();
			int		division();
			int		multiplication();
	private:
			std::stack<int> stack;
			
};

#endif