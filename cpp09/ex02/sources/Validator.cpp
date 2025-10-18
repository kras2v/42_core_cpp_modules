#include "Validator.hpp"

bool Validator::validateInput(char *argv[], std::vector<int> &vect_ints, std::list<int> &list_ints)
{
	for (size_t i = 1; argv[i]; i++)
	{
		try
		{
			size_t pos;
			int numb = std::stoi(argv[i], &pos);

			if (argv[i][pos] != '\0')
				throw std::invalid_argument("not a number");

			if (numb < 0)
				throw std::out_of_range("number cannot be negative");

			vect_ints[i - 1] = numb;
			list_ints.push_back(numb);
		}
		catch(const std::out_of_range& e)
		{
			if (std::string(e.what()).compare("stoi") == 0)
				std::cerr << "Error: " << "number is out of range" << " => " << argv[i] << '\n';
			else
				std::cerr << "Error: " << e.what() << " => " << argv[i] << '\n';
			return false;
		}
		catch (const std::invalid_argument& e)
		{
			if (std::string(e.what()).compare("stoi") == 0)
				std::cerr << "Error: " << "not a number." << " => " << argv[i] << '\n';
			else
				std::cerr << "Error: " << e.what() << " => " << argv[i] << '\n';
			return false;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << argv[i] << '\n';
			return false;
		}
	}
	return true;
}
