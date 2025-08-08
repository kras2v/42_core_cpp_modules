#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>
# include <iostream>

# define my_cout std::cout
# define my_endl std::endl

# define KEY 0
# define VALUE 1

# define NUM_FIELDS 5

class Contact {

	private:
		std::string field[NUM_FIELDS][2];

	public:
		Contact( void );
		~Contact( void );
		void PrintContactDetails();
		std::string *GetField(int index);
		void SetField(int index, std::string);
};


#endif  