#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::string tmp;
	std::fstream file;

	file.open("./data.csv");
	if (!file.is_open())
	{
		std::cout<<"Error couldn't open data.csv\n";
		return ;
	}
	std::getline(file, tmp);
	while (std::getline(file, tmp))
	{
		try
		{
			append(tmp);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return ;
		}
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	this->data = src.data;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::append(std::string str)
{
	size_t pos;

	pos = str.find(',', 0);
	if (pos == str.npos)
		throw databaseError();
	data.insert(std::pair<std::string, float>(str.substr(0, pos), std::stof(str.substr(pos + 1, str.npos))));
	//std::map<std::string, float>::iterator it;
	//it = data.begin();
	//std::cout<<it->first<<" "<<it->second<<"\n";
}

const char *BitcoinExchange::databaseError::what() const throw()
{
	return ("The database is not in a csv format\n");
}
