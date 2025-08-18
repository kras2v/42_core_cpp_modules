#include "Replacer.hpp"

bool is_argc_valid( int argc )
{
	if (argc != 4)
	{
		std::cerr << "Wrong amount of arguments provided."
		<< "(USAGE: filename s1 s2)" << std::endl;
		return (false);
	}
	return (true);
}

int main(int argc, char *argv[])
{
	if (!is_argc_valid(argc)) return (1);
	Replacer replacer(argv[1], argv[2], argv[3]);
	replacer.search_and_replace();
}