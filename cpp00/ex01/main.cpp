#include "PhoneBook.hpp"
#include <iostream>

PhoneBook phoneBook;

void	action(std::string user_input)
{
	if (user_input == "EXIT")
	{
		exit(0);
	}
	if (user_input == "ADD")
	{
		phoneBook.Add();
	}
	if (user_input == "SEARCH")
	{
		phoneBook.Search();
	}
}

int main ()
{
	std::string user_input;
	while (true)
	{
		std::cin >> user_input;
		action(user_input);
	}
	return (0);
}