#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACT_AMOUNT 8

class PhoneBook {

	private:
		Contact		_contacts[MAX_CONTACT_AMOUNT];
		static int	_contactsAmount;

	public:

		int myvar;

		PhoneBook( void );
		~PhoneBook( void );
		void Add();
		void Search();
		void ShowList();
};


#endif