#include "PmergeMe.hpp"

int stoint(const std::string& str)
{

	const char *sptr = str.c_str();
	char *end;
	errno = 0;
	long result = std::strtol(sptr, &end, 10);
	if (sptr == end)
		throw std::invalid_argument("invalid stoi argument");
	if (errno == ERANGE || result < 0 || result > 2147483647)
		throw std::out_of_range("stoi argument out of range");
	return ((int)result);
}

template <typename T, template <typename , class> typename K>
void	print_value(std::string str, K <T, std::allocator<T> > vector)
{
	std::cout<<str<<": ";
	for (typename K <T, std::allocator<T> >::iterator it = vector.begin(); it != vector.end(); ++it)
		std::cout<<*it<<" ";
	std::cout<<std::endl;
}

int main(int argc, char** argv)
{
	std::vector<std::string> tmp;
	PmergeMe sorter;
	
	try
	{
		if (argc < 2)
			throw std::invalid_argument("You need at least 1 argument\n");
		else
		{
			for (int i = 1; argv[i]; i++)
			{
				try
				{
					stoint(argv[i]);
					tmp.push_back(argv[i]);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			}
			for (std::vector<std::string>::iterator it = tmp.begin(); it != tmp.end(); ++it)
				sorter.vector_add(stoint((*it)));
			for (std::vector<std::string>::iterator it = tmp.begin(); it != tmp.end(); ++it)
				sorter.list_add(stoint((*it)));
			print_value("Before", sorter.get_deque());
			sorter.list_sorter(sorter.get_list());
			print_value("After list", sorter.get_list());
			std::cout<<"Time to process a range of "<<tmp.size()<<" elements with std::list : "<<sorter.get_list_time()<<" us"<<std::endl;
			sorter.deque_sorter(sorter.get_deque());
			print_value("After deque", sorter.get_deque());
			std::cout<<"Time to process a range of "<<tmp.size()<<" elements with std::deque : "<<sorter.get_vector_time()<<" us"<<std::endl;
			
			//print_value("After", sorter.vector_sorter());
		
		}
	}
	catch (const std::exception &e)
	{
		std::cerr<<e.what()<<std::endl;
		return 1;
	}
}