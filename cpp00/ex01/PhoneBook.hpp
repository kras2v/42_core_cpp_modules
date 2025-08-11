#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "alias.hpp"

# define MAX_CONTACT_AMOUNT 8

class PhoneBook {

	private:
		Contact	_contacts[MAX_CONTACT_AMOUNT];
		int		_contactsAmount;

	public:

		PhoneBook( void );
		~PhoneBook( void );
		void add();
		void search();
		void showList();
		Contact getContact(int index);
};


#endif