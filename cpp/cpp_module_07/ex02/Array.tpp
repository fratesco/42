template <typename T>
Array<T>::Array()
{
	array = new T[0];
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	array = new T[n];
	_size = n;
	for (unsigned int i = 0; i < n; i++)
		array[i] = 0;
}

template <typename T>
Array<T>::Array(const Array &src)
{
	array = new T[src.size()];
	*this = src;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& src)
{
	_size = src.size();
	for (unsigned int i; i < _size; i++)
		array[i] = src.array[i];
	return *this;
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	if (i >= this->size())
		throw std::out_of_range("Index out of range\n");
	return (array[i]);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= this->size())
		throw std::out_of_range("Index out of range\n");
	return (array[i]);
}

template <typename T>
Array<T>::~Array()
{
	delete array;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}