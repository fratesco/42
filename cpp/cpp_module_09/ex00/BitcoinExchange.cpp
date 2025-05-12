#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	throw DatabaseError();
}

BitcoinExchange::BitcoinExchange(std::string input)
{
	std::string tmp;
	std::fstream file;

	file.open(input.c_str());
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
		throw DatabaseError();
	data.insert(std::pair<std::string, float>(str.substr(0, pos), stofloat(str.substr(pos + 1, str.npos))));
	//std::map<std::string, float>::iterator it;
	//it = data.begin();
	//std::cout<<it->first<<" "<<it->second<<"\n";
}

void BitcoinExchange::append_input(std::string str)
{
	size_t pos;

	pos = str.find('|', 0);
	if (pos == str.npos)
		table.insert(std::pair<std::string, float>(str.substr(0, pos), - 1));
	table.insert(std::pair<std::string, float>(str.substr(0, pos), stofloat(str.substr(pos + 1, str.npos))));
	
}

void BitcoinExchange::add_table(std::string input)
{
	std::string tmp;
	std::fstream file;

	file.open(input.c_str());
	if (!file.is_open())
	{
		std::cout<<"Error couldn't open input file\n";
		return ;
	}
	while (std::getline(file, tmp))
	{
		append_input(tmp);
	}
	file.close();
}

void BitcoinExchange::check_date(std::string date)
{
	int time[3];
	size_t pos;
	const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	pos = date.find('-', 0);
	if (pos == date.npos)
		throw WrongDateFormat();
	time[0] = stoint(date.substr(0, pos));
	pos = date.rfind('-');
	if (pos == date.npos)
		throw WrongDateFormat();
	time[1] = stoint((date.substr(date.find('-') + 1, pos)));
	time[2] = stoint((date.substr(pos + 1, date.npos)));
	if (time[1] <= 0 || time[1] > 12)
		throw WrongDateFormat();
	if (time[2] <= 0 || time[2] > days[time[1] - 1])
		throw WrongDateFormat();
}

std::map<std::string,float>::iterator BitcoinExchange::get_begin_table()
{
	return table.begin();
}

std::map<std::string,float>::iterator BitcoinExchange::get_end_table()
{
	return table.end();
}

std::map<std::string, float>::iterator BitcoinExchange::return_lower(std::map<std::string, float>::iterator it)
{
	return --data.lower_bound(it->first);
}

const char *BitcoinExchange::DatabaseError::what() const throw()
{
	return ("The database is not in a csv format\n");
}

const char *BitcoinExchange::TableFormatError::what() const throw()
{
	return ("The table is not in the correct format\n");
}

const char *BitcoinExchange::WrongDateFormat::what() const throw()
{
	return ("Wrong date format (Y/M/D)\n");
}

const char *BitcoinExchange::ValueError::what() const throw()
{
	return ("The value must be positive and not bigger than 1000\n");
}

int BitcoinExchange::stoint(const std::string& str)
{
		const char *sptr = str.c_str();
		char *end;
		errno = 0;
		long result = std::strtol(sptr, &end, 10);

		if (sptr == end)
			throw std::invalid_argument("invalid stoi argument");
		if (errno == ERANGE)
			throw std::out_of_range("stoi argument out of range");

		return ((int)result);
}

float BitcoinExchange::stofloat(const std::string& str)
	{
		const char *ptr = str.data();
		errno = 0;
		char *end;
		float result = std::strtof(ptr, &end);

		if (ptr == end)
			throw std::invalid_argument("invalid stod argument");
		if (errno == ERANGE)
			throw std::out_of_range("stof argument out of range");
		return result;
	}
