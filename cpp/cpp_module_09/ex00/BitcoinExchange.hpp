#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <exception>
#include <cstdlib>

class BitcoinExchange
{
	public:
			BitcoinExchange();
			BitcoinExchange(std::string input);
			BitcoinExchange(const BitcoinExchange &src);
			BitcoinExchange &operator=(const BitcoinExchange &src);
			~BitcoinExchange();

			void append(std::string str);
			void append_input(std::string str);
			void add_table(std::string input);
			void check_date(std::string date);
			std::map<std::string, float>::iterator get_begin_table();
			std::map<std::string, float>::iterator get_end_table();
			std::map<std::string, float>::iterator return_lower(std::map<std::string, float>::iterator it);

			int stoint(const std::string& str);
			float stofloat(const std::string& str);
			
			class DatabaseError : public std::exception
			{
				public: 
					const char *what() const throw();
			};
			
			class TableFormatError : public std::exception
			{
				public: 
					const char *what() const throw();
			};

			class WrongDateFormat : public std::exception
			{
				public:
					const char *what() const throw();
			};

			class ValueError : public std::exception
			{
				public:
					const char *what() const throw();
			};
			
	private:
			std::map<std::string, float> data;
			std::map<std::string, float> table;
			
};

#endif