#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

struct Data 
{
	int 		i;
	std::string	str;
};

class Serializer
{
	public:
			Serializer(const Serializer &src);
			Serializer &operator=(const Serializer &src);
			~Serializer();

			static uintptr_t serialize(Data* ptr);
			static Data* deserialize(uintptr_t raw);
			
	private:
			Serializer();
			
};

#endif