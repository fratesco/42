#include "PmergeMe.hpp"

void	check_string(std::string str)
{
	if (!atoi(str.c_str()))
	{
		for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		{
			if (*it > '9' || *it < '0')
				throw std::invalid_argument("ERROR");
		}
	}
}
template <typename T>
void	print_value(std::string str, std::vector<T> vector)
{
	std::cout<<str<<": ";
	for (std::vector<T>::iterator it = vector.begin(); it != vector.end(); ++it)
		std::cout<<*it<<" ";
	std::cout<<std::endl;
}

int main(int argc, char** argv)
{
	std::vector<std::string> tmp;
	uint64_t time1 = 0;
	uint64_t time2 = 0;
	PmergeMe sorter;
	
	try
	{
		if (argc < 2)
			throw std::invalid_argument("You need at least 1 argument\n");
		else
		{
			for (int i = 0; argv[i]; i++)
			{
				tmp.push_back(argv[i]);
				check_string(tmp.back());
			}
			print_value("Before", tmp);
			print_value("After", sorter.vector_sorter());
			sorter.list_sorter();
			std::cout<<"Time to process a range of"<<tmp.size()<<"elements with std::vector :"<<sorter.get_vector_time()<<std::endl;
			std::cout<<"Time to process a range of"<<tmp.size()<<"elements with std::list :"<<sorter.get_list_time()<<std::endl;
		
		
		}
	}
	catch (const std::exception &e)
	{
		std::cerr<<e.what()<<std::endl;
		return 1;
	}
}