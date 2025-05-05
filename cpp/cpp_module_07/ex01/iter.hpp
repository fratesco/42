#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename U, typename K>
void iter(T *addr, U const len, K (*func)(T const &))
{
	for(U i = 0; i < len; i++)
		func(addr[i]);
}

template <typename T, typename U, typename K>
void iter(T *addr, U const len, K (*func)(T &))
{
	for(U i = 0; i < len; i++)
		func(addr[i]);
}
#endif