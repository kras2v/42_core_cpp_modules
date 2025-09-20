#include "Bureaucrat.hpp"
#include "Colors.hpp"

void testBureaucratCreation(const std::string& name, int grade, const std::string& testMessage)
{
	std::cout << std::endl
			<< BOLD_BLUE << "[TEST CASE] " << RESET
			<< BOLD << testMessage << RESET << std::endl;

	std::cout << BOLD_CYAN << "➤ Attempting to create Bureaucrat with:" << RESET << std::endl
			<< "   " << BOLD << "Name: " << RESET << name << "\n"
			<< "   " << BOLD << "Grade: " << RESET << grade << std::endl;

	try
	{
		Bureaucrat bureaucrat(name, grade);
		std::cout << BOLD_GREEN << "✔ Successfully created Bureaucrat:" << RESET << std::endl;
		std::cout << bureaucrat << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << BOLD_RED << "✘ Exception: " << RESET << e.what() << std::endl;
	}

	std::cout << BRIGHT_BLACK << std::string(60, '-') << RESET << std::endl;
}

void testBureaucratGradeIncrement(Bureaucrat &bureaucrat, int gradeChangeAmount, const std::string& testMessage)
{
	std::cout << std::endl
		<< BOLD_BLUE << "[TEST CASE] " << RESET
		<< BOLD << testMessage << RESET << std::endl;

	std::cout << BOLD_CYAN << "➤ Attempting to increment bureaucrat grade from " << bureaucrat.getGrade() <<  " by " << gradeChangeAmount << std::endl;
	try
	{
		while (gradeChangeAmount--)
		{
			bureaucrat.increment();
		}
		std::cout << BOLD_GREEN << "✔ Successfully changed Bureaucrat's grade:" << RESET << std::endl;
		std::cout << bureaucrat << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << BOLD_RED << "✘ Exception: " << RESET << e.what() << std::endl;
	}
	std::cout << BRIGHT_BLACK << std::string(60, '-') << RESET << std::endl;
}

void testBureaucratGradeDecrement(Bureaucrat &bureaucrat, int gradeChangeAmount, const std::string& testMessage)
{
	std::cout << std::endl
			<< BOLD_BLUE << "[TEST CASE] " << RESET
			<< BOLD << testMessage << RESET << std::endl;

	std::cout << BOLD_CYAN << "➤ Attempting to decrement bureaucrat grade from " << bureaucrat.getGrade() <<  " by " << gradeChangeAmount << std::endl;
	try
	{
		while (gradeChangeAmount--)
		{
			bureaucrat.decrement();
		}
		std::cout << BOLD_GREEN << "✔ Successfully changed Bureaucrat's grade:" << RESET << std::endl;
		std::cout << bureaucrat << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << BOLD_RED << "✘ Exception: " << RESET << e.what() << std::endl;
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
	newTestsTitle("Bureaucrat creation tests:");
	testBureaucratCreation("Bob", 5, "Valid bureaucrat");
	testBureaucratCreation("BobLow", 151, "Grade too low bureaucrat");
	testBureaucratCreation("BobHigh", -5, "Grade too high bureaucrat");

	{
		newTestsTitle("Bureaucrat increment tests:");
		int grade = 3;
		Bureaucrat bob("bob", grade);
		testBureaucratGradeIncrement(bob, 1, "Valid score increment");
		testBureaucratGradeIncrement(bob, 1, "Valid score increment");
		testBureaucratGradeIncrement(bob, 100, "Invalid score increment (too high)");
	}

	{
		newTestsTitle("Bureaucrat decrement tests:");
		int grade = 5;
		Bureaucrat bob("bob", grade);
		testBureaucratGradeDecrement(bob, 1, "Valid score decrement");
		testBureaucratGradeDecrement(bob, 2, "Valid score decrement");
		testBureaucratGradeDecrement(bob, 100, "Valid score decrement");
		testBureaucratGradeDecrement(bob, 100, "Invalid score decrement");
	}
}

