#include "easyfind.hpp"

int main()
{
	std::vector<int> v = {1, 3, 6, 2, 9};

	try
	{
		auto it = easyfind(v, 6);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::vector<int>::iterator it = easyfind(v, 22);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::vector<std::string> strings = {"hello", "world", "!"};
		std::vector<int>::iterator it = easyfind(v, 10);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}