#include "IOHelper.hpp"

IOHelper::IOHelper()
{
	#ifdef DEBUG
		std::cout << "IOHelper constructor" << std::endl;
	#endif
}

IOHelper::~IOHelper()
{
	#ifdef DEBUG
		std::cout << "IOHelper constructor" << std::endl;
	#endif
}

void IOHelper::printTableHeader(Contact *contact)
{
	if (contact == nullptr)
		return ;
	IOHelper::printLine('-', 45);
	my_cout << '|';
	contact->formatOutput("index");
	for (size_t i = 0; i < NUM_FIELDS - 2; i++)
	{
		contact->formatOutput(contact->getField(i)[KEY]);
	}
	my_cout << my_endl;
	IOHelper::printLine('-', 45);
}

void IOHelper::printTableRow(int index, Contact *contact)
{
	my_cout << '|';
	contact->formatOutput((index));
	for (size_t j = 0; j < NUM_FIELDS - 2; j++)
	{
		contact->formatOutput(contact->getField(j)[VALUE]);
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
		if (!getline(std::cin, input_string))
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
