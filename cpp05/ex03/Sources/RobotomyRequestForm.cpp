#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("home")
{
	#ifdef DEBUG
		std::cout << "RobotomyRequestForm default constructor" << std::endl;
	#endif
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	#ifdef DEBUG
		std::cout << "ShrubberyCreationForm default constructor" << std::endl;
	#endif
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm(other)
{
	#ifdef DEBUG
		std::cout << "RobotomyRequestForm copy constructor" << std::endl;
	#endif
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	#ifdef DEBUG
		std::cout << "RobotomyRequestForm destructor" << std::endl;
	#endif
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	#ifdef DEBUG
		std::cout << "RobotomyRequestForm copy assignment operator" << std::endl;
	#endif
	if (this != &other)
	{
		*this = other;
	}
	return *this;
}

void RobotomyRequestForm::action() const
{
	srand(time(nullptr));
	int iterTimes = rand() % 1 + 5;
	std::string noises[3] = 
	{
		"💥 brrrrRRRRRRRRRRRRRrrrrrrrrrrrrRRRRRrrrrrRRRrrr...",
		"🔩 drrRRRrrrRRRrrRRRrrrRRRrrRRRrrrRRRrr..",
		"⚙️  vvvvvvVVVVVVVvvvvvvvvVVVVVVvvvvvvvv..."
	};
	int workTime, noiseNumber;
	for (int i = 0; i < iterTimes; i++)
	{
		workTime = rand() % 500 + 500;
		noiseNumber = rand() % 3;
		std::this_thread::sleep_for(std::chrono::milliseconds(workTime));
		std::cout << noises[noiseNumber] << std::endl;
	}
	int result = rand () % 2;
	if (result)
		std::cout << this->_target << " successfully robotomized!" << std::endl;
	else
		std::cout << this->_target << " robotomy failed." << std::endl;
}

const std::string RobotomyRequestForm::getAdditionalInfo() const
{
	return "- Target: " + this->_target;
}

std::string RobotomyRequestForm::checkTarget(std::string target) const
{
	if (target.empty()) return "empty";
	return target;
}