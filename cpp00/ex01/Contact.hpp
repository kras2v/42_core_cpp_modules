#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include "alias.hpp"

# define KEY 0
# define VALUE 1

# define NUM_FIELDS 5

class Contact {

	private:
		my_string _field[NUM_FIELDS][2];

	public:
		Contact( void );
		~Contact( void );
		void printContactDetails();
		my_string *getField(int index);
		void setField(int index, my_string);
};


#endif  