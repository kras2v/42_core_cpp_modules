#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

void testFormCreation(const std::string& name, int signGrade, int execGrade, const std::string& testMessage)
{
	std::cout << std::endl
		<< BOLD_BLUE << "[TEST CASE] " << RESET
		<< BOLD << testMessage << RESET << std::endl;

	std::cout << BOLD_CYAN << "➤ Attempting to create Form with:" << RESET << std::endl
		<< "   " << BOLD << "Name: " << RESET << name << "\n"
		<< "   " << BOLD << "Sign Grade: " << RESET << signGrade << "\n"
		<< "   " << BOLD << "Exec Grade: " << RESET << execGrade << std::endl;

	try
	{
		Form form(name, signGrade, execGrade);
		std::cout << BOLD_GREEN << "✔ Successfully created Form:" << RESET << std::endl;
		std::cout << form << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << BOLD_RED << "✘ Exception: " << RESET << e.what() << std::endl;
	}

	std::cout << BRIGHT_BLACK << std::string(60, '-') << RESET << std::endl;
}

void testFormSigning(Form& form, Bureaucrat& bureaucrat, const std::string& testMessage)
{
	std::cout << std::endl
		<< BOLD_BLUE << "[TEST CASE] " << RESET
		<< BOLD << testMessage << RESET << std::endl;

	std::cout << BOLD_CYAN << "➤ " << bureaucrat.getName() << " (grade " << bureaucrat.getGrade()
		<< ") attempts to sign form \"" << form.getName() << "\" (required grade: "
		<< form.getGradeRequiredToSign() << ")"  << RESET << std::endl << std::endl;

	if (bureaucrat.signForm(form))
	{
		std::cout << BOLD_GREEN << std::endl << "✔ Form signed successfully!" << RESET << std::endl;
		std::cout << form << std::endl;
	}
	else
	{
		std::cerr << BOLD_RED << std::endl << "✘ Exception" << std::endl;
	}
	std::cout << BRIGHT_BLACK << std::string(60, '-') << RESET << std::endl;
}

void newTestsTitle(const std::string& title)
{
	std::cout << std::endl
		<< BOLD_MAGENTA << std::string(60, '=') << RESET << std::endl
		<< BOLD << UNDERLINE << "[ " << title << " ]" << RESET << std::endl
		<< BOLD_MAGENTA << std::string(60, '=') << RESET << std::endl;
}

int main()
{
	newTestsTitle("Form creation tests:");
	testFormCreation("FormA", 10, 20, "Valid form");
	testFormCreation("FormLow", 151, 20, "Sign grade too low");
	testFormCreation("FormHigh", 0, 20, "Sign grade too high");
	testFormCreation("FormExecLow", 10, 151, "Exec grade too low");
	testFormCreation("FormExecHigh", 10, 0, "Exec grade too high");

	newTestsTitle("Form signing tests:");
	Form form1("TopSecret", 5, 10);
	Form form2("EasyForm", 100, 100);
	Form form3("ImpossibleForm", 1, 1);

	Bureaucrat bob("Bob", 5);      // grade 5
	Bureaucrat alice("Alice", 10); // grade 10
	Bureaucrat tom("Tom", 100);    // grade 100
	Bureaucrat boss("Boss", 1);    // grade 1

	testFormSigning(form1, bob, "Bob signs TopSecret (should succeed)");
	testFormSigning(form1, alice, "Alice signs TopSecret (should fail)");
	testFormSigning(form2, tom, "Tom signs EasyForm (should succeed)");
	testFormSigning(form2, alice, "Alice signs EasyForm (should succeed)");
	testFormSigning(form3, boss, "Boss signs ImpossibleForm (should succeed)");
	testFormSigning(form3, bob, "Bob signs ImpossibleForm (should fail)");
}