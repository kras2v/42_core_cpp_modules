#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 145, 137)
{
	#ifdef DEBUG
		std::cout << "RobotomyRequestForm default constructor" << std::endl;
	#endif
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	#ifdef DEBUG
		std::cout << "RobotomyRequestForm destructor" << std::endl;
	#endif

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	#ifdef DEBUG
		std::cout << "RobotomyRequestForm copy constructor" << std::endl;
	#endif
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	#ifdef DEBUG
		std::cout << "RobotomyRequestForm copy assignment operator" << std::endl;
	#endif
}
