#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &src) : stack(src.stack)
{
}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
		stack = src.stack;
	return *this;
}

RPN::~RPN()
{
}

void RPN::push(int a)
{
	stack.push(a);
}

int RPN::pop()
{
	int top = stack.top();
	stack.pop();
	return top;
}

int RPN::addiction()
{
	if (stack.size() < 2)
		throw std::invalid_argument("ERROR");
	int a2 = pop();
	int a1 = pop();

	push(a1 + a2);
	return (stack.top());
}

int RPN::subtraction()
{
	if (stack.size() < 2)
		throw std::invalid_argument("ERROR");
	int a2 = pop();
	int a1 = pop();

	push(a1 - a2);
	return (stack.top());
}

int RPN::division()
{
	if (stack.size() < 2)
		throw std::invalid_argument("ERROR");
	int a2 = pop();
	int a1 = pop();

	push(a1 / a2);
	return (stack.top());
}

int RPN::multiplication()
{
	if (stack.size() < 2)
		throw std::invalid_argument("ERROR");
	int a2 = pop();
	int a1 = pop();

	push(a1 * a2);
	return (stack.top());
}