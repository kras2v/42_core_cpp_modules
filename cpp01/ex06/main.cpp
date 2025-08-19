#include "Harl.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Wrong amount of arguments. Usage: ./harlFilter \"level\"" << std::endl;
		return (1);
	}
	Harl harl;
	harl.complain(argv[1]);
	return (0);
}