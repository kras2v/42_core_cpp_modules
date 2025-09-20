#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 72, 45)
{
	#ifdef DEBUG
		std::cout << "PresidentialPardonForm default constructor" << std::endl;
	#endif
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	#ifdef DEBUG
		std::cout << "PresidentialPardonForm destructor" << std::endl;
	#endif

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	#ifdef DEBUG
		std::cout << "PresidentialPardonForm copy constructor" << std::endl;
	#endif
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	#ifdef DEBUG
		std::cout << "PresidentialPardonForm copy assignment operator" << std::endl;
	#endif
}
