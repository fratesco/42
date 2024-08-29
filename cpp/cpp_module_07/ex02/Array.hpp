#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
	public:
			Array();
			Array(unsigned int n);
			Array(const Array &src);
			Array &operator=(const Array &src);
			T &operator[](unsigned int i);
			const T &operator[](unsigned int i) const;
			~Array();

			unsigned int size() const;
			
	private:
		T *array;
		unsigned int _size;
			
};

#include "Array.tpp"

#endif