#ifndef IOHelper_HPP
# define IOHelper_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "Contact.hpp"
# include "alias.hpp"

# define WIDE_SIZE 10

class IOHelper
{
	private:
	public:
		IOHelper();
		~IOHelper();
		static void printTableHeader(Contact contact);
		static void printTableRow(int index, Contact contact);
		static void printLine(char character, int numb_symbols);
		static void printListOfCommands( void );
		static void printWelcomeMessage( void );
		static void formatOutput(my_string string);
		static my_string getUserInput(my_string prompt);
};

#endif