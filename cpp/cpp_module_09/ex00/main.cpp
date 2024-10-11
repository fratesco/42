#include "BitcoinExchange.hpp"



int main (int argc, char **argv)
{
	if (argc < 2)
		std::cout<<"Input file necessary\n";
	else if (argc > 3)
		std::cout<<"Too many arguments\n";
	else
	{
		BitcoinExchange database("./data.csv");

		database.add_table(argv[1]);

		for(std::map<std::string, float>::iterator it = database.get_begin_table(); it != database.get_end_table(); ++it)
		{
			try
			{
				database.check_date(it->first);
				if (it->second < 0 || it->second > 1000)
					throw BitcoinExchange::ValueError();
				std::cout << it->first << " => " << it->second << " = " << it->second * database.return_lower(it)->second << "\n";
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what();
			}
			
		}
		
	}

	return 0;
}