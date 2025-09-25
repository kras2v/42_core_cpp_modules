#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"
# include "Colors.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		std::string checkTarget(std::string target) const;
		const std::string getAdditionalInfo() const override;

	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

		PresidentialPardonForm(std::string target);
		void action() const override;
};

#endif /* PRESIDENTIAL_PARDON_FORM_HPP */