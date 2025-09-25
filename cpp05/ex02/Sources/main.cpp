#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"
#include <iostream>

void testFormCreation(const std::string& type, const std::string& target)
{
	std::cout << std::endl << BOLD_BLUE << "[CREATION TEST] " << RESET << type << " for target: " << target << std::endl;
	try
	{
		if (type == "ShrubberyCreation") ShrubberyCreationForm form(target);
		else if (type == "RobotomyRequest") RobotomyRequestForm form(target);
		else if (type == "PresidentialPardon") PresidentialPardonForm form(target);
		std::cout << BOLD_GREEN << "✔ " << type << "Form created." << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << BOLD_RED << "✘ Exception: " << RESET << e.what() << std::endl;
	}
	std::cout << BRIGHT_BLACK << std::string(60, '-') << RESET << std::endl;
}

void testFormExecution(const std::string& testMessage, AForm& form, Bureaucrat& signer, Bureaucrat& executor)
{
	std::cout << std::endl << BOLD_BLUE << "[EXECUTION TEST] " << RESET << testMessage << std::endl;
	std::cout << "Signer details: " << std::endl << signer;
	std::cout << BOLD_WHITE << std::string(35, '.') << RESET << std::endl;
	std::cout << "Executor details: " << std::endl << executor;
	std::cout << BOLD_WHITE << std::string(35, '.') << RESET << std::endl;
	std::cout << "Form details: " << std::endl << form;
	std::cout << BOLD_YELLOW << std::string(35, '.') << RESET << std::endl;
	try
	{
		std::cout << BOLD_CYAN << "➤ " << signer.getName() << " attempts to sign..." << RESET << std::endl;
		form.beSigned(signer);
		std::cout << BOLD_GREEN << "✔ Signed successfully." << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << BOLD_RED << "✘ Exception: "  << RESET  << e.what() << std::endl;
	}

	try
	{
		std::cout << BOLD_CYAN << "➤ " << executor.getName() << " attempts to execute..." << RESET << std::endl;
		form.execute(executor);
		std::cout << BOLD_GREEN << "✔ Executed successfully." << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << BOLD_RED << "✘ Exception: " << RESET << e.what() << std::endl;
	}
	std::cout << BRIGHT_BLACK << std::string(60, '-') << RESET << std::endl;
}

int main()
{
	// Creation tests
	testFormCreation("ShrubberyCreation", "garden");
	testFormCreation("RobotomyRequest", "Bender");
	testFormCreation("PresidentialPardon", "Arthur Dent");

	// Bureaucrats
	Bureaucrat low("LowRank", 150);
	Bureaucrat shrubSign("ShrubSign", 135);
	Bureaucrat shrubExec("ShrubExec", 125);
	Bureaucrat robotSign("RobotSign", 72);
	Bureaucrat robotExec("RobotExec", 45);
	Bureaucrat presSign("PresSign", 25);
	Bureaucrat presExec("PresExec", 5);

	// Shrubbery: success
	ShrubberyCreationForm shrubbery("garden");
	testFormExecution("ShrubberyCreationForm (success)", shrubbery, shrubSign, shrubExec);

	// Shrubbery: fail (executor grade too low)
	ShrubberyCreationForm shrubberyFail("yard");
	testFormExecution("ShrubberyCreationForm (fail)", shrubberyFail, shrubSign, low);

	// Robotomy: success
	RobotomyRequestForm robotomy("Bender");
	testFormExecution("RobotomyRequestForm (success)", robotomy, robotSign, robotExec);

	// Robotomy: fail (not signed)
	RobotomyRequestForm robotomyFail("Fry");
	std::cout << std::endl << BOLD_BLUE << "[EXECUTION TEST] RobotomyRequestForm (not signed)" << RESET << std::endl;
	try
	{
		robotomyFail.execute(robotExec);
	}
	catch (const std::exception& e)
	{
		std::cerr << BOLD_RED << "✘ Exception: " << RESET << e.what() << std::endl;
	}
	std::cout << BRIGHT_BLACK << std::string(60, '-') << RESET << std::endl;

	// Presidential: success
	PresidentialPardonForm pardon("Arthur Dent");
	testFormExecution("PresidentialPardonForm (success)", pardon, presSign, presExec);

	// Presidential: fail (signer grade too low)
	PresidentialPardonForm pardonFail("Ford Prefect");
	testFormExecution("PresidentialPardonForm (fail)", pardonFail, shrubSign, presExec);
}
