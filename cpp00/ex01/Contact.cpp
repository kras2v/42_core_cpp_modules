#include "Contact.hpp"

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
				this->field[i][KEY] = "first name";
				break;
			case 1:
				this->field[i][KEY] = "last name";
				break;
			case 2:
				this->field[i][KEY] = "nickname";
				break;
			case 3:
				this->field[i][KEY] = "phone number";
				break;
			case 4:
				this->field[i][KEY] = "darkest secret";
				break;
			default:
				break;
		}
		this->field[i][1] = "";
	}
}

Contact::~Contact( void )
{
	#ifdef DEBUG
		std::cout << "Contact destructor" << std::endl;
	#endif
}

void Contact::PrintContactDetails( void )
{
	for (size_t i = 0; i < 5; i++)
	{
		my_cout << this->field[i][KEY] << "\t" << this->field[i][VALUE] << my_endl;
	}
}

std::string *Contact::GetField(int index)
{
	return (this->field[index]);
}

void Contact::SetField(int index, std::string new_value)
{
	this->field[index][VALUE] = new_value;
}