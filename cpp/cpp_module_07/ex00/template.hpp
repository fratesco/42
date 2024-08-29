#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

template <typename T>
void swap (T &a, T &b)
{
	T const c = a;
	a = b;
	b = c;
}

template <typename T>
T min(T const a, T const b)
{
	return (a < b ? a : b);
}

template <typename T>
T max(T const a, T const b)
{
	return (a > b ? a : b);
}

#endif