#include "IOHelper.hpp"

IOHelper::IOHelper()
{
	#ifdef DEBUG
		my_cout << "IOHelper constructor" << my_endl;
	#endif
}

IOHelper::~IOHelper()
{
	#ifdef DEBUG
		my_cout << "IOHelper constructor" << my_endl;
	#endif
}

void IOHelper::formatOutput(my_string string)
{
	my_string buffer;
	buffer = string.substr(0, 9);
	int size = string.size();
	if (size > 9)
	{
		my_cout << std::setw(WIDE_SIZE - 1);
		my_cout << buffer << '.';
	}
	else
	{
		my_cout << std::setw(WIDE_SIZE);
		my_cout << buffer;
	}
	my_cout << '|';
}

void IOHelper::printTableHeader(Contact contact)
{
	IOHelper::printLine('-', 45);
	my_cout << '|';
	IOHelper::formatOutput("index");
	for (size_t i = 0; i < NUM_FIELDS - 2; i++)
	{
		IOHelper::formatOutput(contact.getField(i)[KEY]);
	}
	my_cout << my_endl;
	IOHelper::printLine('-', 45);
}

void IOHelper::printTableRow(int index, Contact contact)
{
	my_cout << '|';
	IOHelper::formatOutput(std::to_string(index));
	for (size_t j = 0; j < NUM_FIELDS - 2; j++)
	{
		IOHelper::formatOutput(contact.getField(j)[VALUE]);
	}
	my_cout << my_endl;
	IOHelper::printLine('-', 45);
}

void IOHelper::printLine(char character, int numb_symbols)
{
	my_cout << my_string (numb_symbols, character) << my_endl;
}

void IOHelper::printListOfCommands( void )
{
	IOHelper::printLine('=',37);
	my_cout << "Use one of the following command: " << my_endl << my_endl;
	my_cout << "ADD\t\t" << "Save a new contact" << my_endl;
	my_cout << "SEARCH\t\t"<< "Display a specific contact" << my_endl;
	my_cout << "EXIT\t\t"<< "Exit program" << my_endl << my_endl;
}

void IOHelper::printWelcomeMessage( void )
{
	IOHelper::printLine('=', 37);
	my_cout << "|  Welcome to my Awesome PhoneBook  |" << my_endl;
	printListOfCommands();
}

my_string IOHelper::getUserInput(my_string prompt)
{
	my_string input_string;
	my_cout << prompt;
	while (true)
	{
		if (getline(my_cin, input_string).fail())
		{
			my_cin.clear();
			clearerr(stdin);
			continue;
		}
		if (input_string.empty())
		{
			my_cerr << "The input is invalid, please try again :c" << my_endl;
			my_cout << prompt;
		}
		else
		{
			return (input_string);
		}
	}
	return (input_string);
}
