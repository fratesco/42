#include "Serializer.hpp"

int main()
{
	Data data;

	data.i = 40;

	Data *ptr = Serializer::deserialize(Serializer::serialize(&data));

	ptr->str = "hello!";

	std::cout<<&data<<(char)32<<ptr<<std::endl<<ptr->i<<data.str<<std::endl;
}