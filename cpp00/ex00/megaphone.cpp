#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string string = argv[i];
			for (char &c : string)
			{
				c = toupper(c);
			}
			std::cout << string;
		}
	}
	std::cout << std::endl;
}