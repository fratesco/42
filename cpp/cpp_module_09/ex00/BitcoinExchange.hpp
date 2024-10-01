#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <exception>

class BitcoinExchange
{
	public:
			BitcoinExchange();
			BitcoinExchange(const BitcoinExchange &src);
			BitcoinExchange &operator=(const BitcoinExchange &src);
			~BitcoinExchange();

			void append(std::string str);

			class databaseError : public std::exception
			{
				public: 
					const char *what() const throw();
			};
			
	private:
			std::map<std::string, float> data;
			
};

#endif