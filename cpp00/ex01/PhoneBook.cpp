#include <iostream>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
	#ifdef DEBUG
	std::cout << "PhoneBook constructor" << std::endl;
	#endif
}

PhoneBook::~PhoneBook( void )
{
	#ifdef DEBUG
	std::cout << "PhoneBook destructor" << std::endl;
	#endif
}

void PhoneBook::ShowList()
{
	for (size_t i = 0; i < MAX_CONTACT_AMOUNT; i++)
	{
		this->_contacts[i].PrintContactDetails();
	}
}

void PhoneBook::Add()
{
	for (size_t i = 0; i < NUM_FIELDS; i++)
	{
		Contact newContact;
		my_cout << "Please enter " << newContact.GetField(i)[KEY] << ": ";
		std::string input_string = "";
		while (input_string == "")
		{
			std::cin >> input_string;
			if (input_string == "")
				my_cout << "The input is invalid, please try again :c" << my_endl;
		}
		newContact.SetField(i, input_string);
	}
	
}

void PhoneBook::Search()
{
}