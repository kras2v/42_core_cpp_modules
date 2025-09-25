#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <iostream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		std::string checkTarget(std::string target) const;
		const std::string getAdditionalInfo() const override;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		void action() const override;
};

#endif /* SHRUBBERY_CREATION_FORM_HPP */