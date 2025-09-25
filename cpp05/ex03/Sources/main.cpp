#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"
#include <iostream>

void testInternFormCreation(Intern& intern, const std::string& type, const std::string& target, const std::string& testMessage)
{
	std::cout << std::endl << BOLD_BLUE << "[INTERN FORM CREATION TEST] " << RESET << testMessage << std::endl;
	std::cout << BOLD_CYAN << "➤ Intern attempts to create form: \"" << type << "\" for target: " << target << RESET << std::endl;
	AForm* form = intern.makeForm(type, target);
	if (form)
	{
		std::cout << BOLD_GREEN << "✔ Form created: " << form->getName() << RESET << std::endl;
		std::cout << *form << std::endl;
		delete form;
	}
	else
	{
		std::cerr << BOLD_RED << "✘ Form creation failed: Unknown form type" << RESET << std::endl;
	}
	std::cout << BRIGHT_BLACK << std::string(60, '-') << RESET << std::endl;
}

int main()
{
	Intern intern;

	testInternFormCreation(intern, "robotomy request", "Bender", "RobotomyRequestForm (valid)");
	testInternFormCreation(intern, "presidential pardon", "Arthur Dent", "PresidentialPardonForm (valid)");
	testInternFormCreation(intern, "shrubbery creation", "garden", "ShrubberyCreationForm (valid)");
	testInternFormCreation(intern, "unknown form", "Nobody", "Unknown form type (should fail)");
}