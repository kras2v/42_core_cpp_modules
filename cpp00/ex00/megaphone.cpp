#include <iostream>
#define my_cout std::cout
#define my_endl std::endl
#define my_string std::string

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		my_cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			my_string string = argv[i];
			for (char &c : string)
			{
				c = toupper(c);
			}
			my_cout << string;
		}
	}
	my_cout << my_endl;
}