#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange exchange(argv[1]);
		exchange.readFile();
	}
	catch (const BitcoinExchange::FileException& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}