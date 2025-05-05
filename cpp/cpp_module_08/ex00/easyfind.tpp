#include <exception>
#include <vector>
#include <map>
#include <algorithm>

template <typename T>
void easyfind(T container, int needle)
{
	typename T::iterator it = std::find(container.begin(), container.end(), needle);
	if (it == container.end())
	{
		//if (*it != needle)
			throw std::invalid_argument("Needle not found\n");
	}
}