#include "Intern.hpp"

Intern::Intern()
{
	#ifdef DEBUG
		std::cout << "Intern default constructor" << std::endl;
	#endif
}

Intern::~Intern()
{
	#ifdef DEBUG
		std::cout << "Intern destructor" << std::endl;
	#endif
}

int getTypeNumber(std::string type)
{
	std::string types[] =
	{
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
	size_t i = 0;
	for ( ; i < 3; i++)
	{
		if (types[i] == type) break;
	}
	return (i);
}

AForm *Intern::makeForm(std::string type, std::string target) const
{
	AForm *form = nullptr;
	switch (getTypeNumber(type))
	{
		case ROBOTOMY:
			form = new RobotomyRequestForm(target);
			break;
		case PRESEDENTIAL:
			form = new PresidentialPardonForm(target);
			break;
		case SHRUBBERY:
			form = new ShrubberyCreationForm(target);
			break;
		default:
			form = nullptr;
	}
	if (form) std::cout << "Intern creates " << form->getName() << std::endl;
	else std::cerr << "Form creation failed" << std::endl;
	return (form);
}
