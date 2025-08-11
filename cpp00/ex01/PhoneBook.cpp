#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "IOHelper.hpp"

PhoneBook::PhoneBook( void )
{
	#ifdef DEBUG
		my_cout << "PhoneBook constructor" << my_endl;
	#endif
	this->_contactsAmount = 0;
}

PhoneBook::~PhoneBook( void )
{
	#ifdef DEBUG
		my_cout << "PhoneBook destructor" << my_endl;
	#endif
}

void PhoneBook::showList()
{
	IOHelper::printTableHeader(this->_contacts[0]);
	for (size_t i = 0; i < MAX_CONTACT_AMOUNT && this->_contacts[i].getField(0)[VALUE] != ""; i++)
	{
		IOHelper::printTableRow(i, this->getContact(i));
	}
}

void PhoneBook::add()
{
	Contact newContact;
	for (size_t i = 0; i < NUM_FIELDS; i++)
	{
		my_string prompt = "Please enter " + newContact.getField(i)[KEY] + ": ";
		my_string user_input = IOHelper::getUserInput(prompt);
		newContact.setField(i, user_input);
	}
	this->_contacts[this->_contactsAmount % MAX_CONTACT_AMOUNT] = newContact;
	this->_contactsAmount++;
	my_cout << "Succesfully added contact!" << my_endl;
}

void PhoneBook::search()
{
	this->showList();
	try
	{
		int index;
		my_string prompt = "PLease enter index of element you want to search: ";
		my_string user_input = IOHelper::getUserInput(prompt);
		index = std::stoi(user_input);
		if (index < 0 || index > MAX_CONTACT_AMOUNT)
		{
			throw std::out_of_range("Index out of range");
		}
		if (this->_contacts[index].getField(0)[VALUE].empty())
		{
			throw std::logic_error("Contact doesn't exist");
		}
		my_cout << my_endl << "Information about contact #" << index << my_endl;
		this->_contacts[index].printContactDetails();
	}
	catch(const std::exception& e)
	{
		#ifdef DEBUG
			my_cerr << e.what() << my_endl;
		#endif
		my_cerr << "Sorry, cannot find record with this index." << my_endl;
	}
}

Contact PhoneBook::getContact(int index)
{
	return (this->_contacts[index]);
}