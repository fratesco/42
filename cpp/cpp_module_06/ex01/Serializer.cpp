#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &src)
{
}

Serializer &Serializer::operator=(const Serializer &src)
{
	return *this;
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data* ptr)
{
	//return (uintptr_t)(void *)ptr;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	//return (Data *)(void *)raw;
	return reinterpret_cast<Data *>(raw);
}