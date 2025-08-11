#include "Contact.hpp"
#include <iomanip>

Contact::Contact( void )
{
	#ifdef DEBUG
		std::cout << "Contact constructor" << std::endl;
	#endif
	for (size_t i = 0; i < 5; i++)
	{
		switch (i)
		{
			case 0:
				this->_field[i][KEY] = "first name";
				break;
			case 1:
				this->_field[i][KEY] = "last name";
				break;
			case 2:
				this->_field[i][KEY] = "nickname";
				break;
			case 3:
				this->_field[i][KEY] = "phone number";
				break;
			case 4:
				this->_field[i][KEY] = "darkest secret";
				break;
			default:
				break;
		}
		this->_field[i][1] = "";
	}
}

Contact::~Contact( void )
{
	#ifdef DEBUG
		std::cout << "Contact destructor" << std::endl;
	#endif
}

void Contact::printContactDetails( void )
{
	for (size_t i = 0; i < NUM_FIELDS; i++)
	{
		my_cout << this->_field[i][KEY] << ": " << this->_field[i][VALUE] << my_endl;
	}
}

std::string *Contact::getField(int index)
{
	return (this->_field[index]);
}

void Contact::setField(int index, std::string new_value)
{
	this->_field[index][VALUE] = new_value;
}