#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 25, 5)
{
	#ifdef DEBUG
		std::cout << "ShrubberyCreationForm default constructor" << std::endl;
	#endif
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	#ifdef DEBUG
		std::cout << "ShrubberyCreationForm destructor" << std::endl;
	#endif

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	#ifdef DEBUG
		std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
	#endif
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	#ifdef DEBUG
		std::cout << "ShrubberyCreationForm copy assignment operator" << std::endl;
	#endif
}
