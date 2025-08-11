#include "PhoneBook.hpp"
#include "IOHelper.hpp"
#include <iostream>
#include <iomanip>

PhoneBook phoneBook;

void	action(my_string user_input)
{
	if (user_input == "EXIT")
	{
		my_cout << "Bye-bye :D" << my_endl;
		exit(0);
	}
	else if (user_input == "ADD")
	{
		phoneBook.add();
	}
	else if (user_input == "SEARCH")
	{
		phoneBook.search();
	}
	else
	{
		my_cout << "I don't know what is \"" << user_input
		<< "\" Please enter valid command (ADD, SEARCH, EXIT)" << my_endl;
	}
}

int main ()
{
	IOHelper::printWelcomeMessage();
	while (true)
	{
		my_string user_input = IOHelper::getUserInput("");
		action(user_input);
		IOHelper::printListOfCommands();
	}
	return (0);
}