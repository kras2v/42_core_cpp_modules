#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Usage: " << argv[0] << " <RPN expression>" << std::endl;
		return 1;
	}
	try
	{
		std::string expression = std::string(argv[1]);
		std::cout << RPN::calculate(expression) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error" << '\n';
		return 1;
	}
	return 0;
}