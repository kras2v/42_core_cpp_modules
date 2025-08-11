#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cerr << "Wrong amount of arguments provided."
		<< "(USAGE: filename s1 s2)" << std::endl;
	}
	
	return (0);
}