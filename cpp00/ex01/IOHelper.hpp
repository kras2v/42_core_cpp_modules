#ifndef IOHelper_HPP
#define IOHelper_HPP

# include <string>
# include <iostream>
# include "Contact.hpp"

# define my_string std::string
# define my_cout std::cout
# define my_cerr std::cerr
# define my_cin std::cin
# define my_endl std::endl

class IOHelper
{
	private:
	public:
		IOHelper();
		~IOHelper();
		static void printTableHeader(Contact *contact);
		static void printTableRow(int index, Contact *contact);
		static void printLine(char character, int numb_symbols);
		static void printListOfCommands( void );
		static void printWelcomeMessage( void );
		static my_string getUserInput(my_string prompt);
};

#endif