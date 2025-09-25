#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
# include <thread>
# include <random>
# include <chrono>

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		std::string checkTarget(std::string target) const;
		const std::string getAdditionalInfo() const override;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		void action() const override;
};

#endif /* ROBOTOMY_REQUEST_FORM_HPP */