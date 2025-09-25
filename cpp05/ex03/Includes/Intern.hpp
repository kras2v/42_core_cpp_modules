#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <string>

typedef enum e_types
{
	ROBOTOMY,
	PRESEDENTIAL,
	SHRUBBERY
}t_types;

class Intern
{
	public:
		Intern();
		Intern(const Intern &other) = delete;
		Intern &operator=(const Intern &other) = delete;
		~Intern();

		AForm *makeForm(std::string type, std::string target) const;
};

#endif /* INTERN_HPP */