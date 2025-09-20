#include "AForm.hpp"

AForm::AForm():
	_name("default"),
	_gradeRequiredToSign(5),
	_gradeRequiredToExecute(5)
{
	#ifdef DEBUG
		std::cout << "Form default constructor" << std::endl;
	#endif
}

AForm::AForm(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute) :
	_name(name),
	_gradeRequiredToSign(checkGrade(gradeRequiredToSign)),
	_gradeRequiredToExecute(checkGrade(gradeRequiredToExecute))
{
	#ifdef DEBUG
		std::cout << "Form parametrized constructor" << std::endl;
	#endif
}

AForm::~AForm()
{
	#ifdef DEBUG
		std::cout << "Form default destructor" << std::endl;
	#endif
}

int AForm::checkGrade(int grade) const
{
	if (grade < HIGHEST)
	{
		throw AForm::GradeTooHighException();
	}
	if (grade > LOWEST)
	{
		throw AForm::GradeTooLowException();
	}
	return (grade);
}

AForm::AForm(const AForm &other) :
	_isSigned(other._isSigned),
	_name(other._name),
	_gradeRequiredToSign(other._gradeRequiredToSign),
	_gradeRequiredToExecute(other._gradeRequiredToExecute)
{
	#ifdef DEBUG
		std::cout << "Form copy constructor" << std::endl;
	#endif
}

AForm &AForm::operator=(const AForm &other)
{
	#ifdef DEBUG
		std::cout << "Form copy assignment operator" << std::endl;
	#endif
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

const char *AForm::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low!");
}

bool	AForm::getIsSigned() const
{
	return this->_isSigned;
}

const std::string	AForm::getName() const
{
	return this->_name;
}

int	AForm::getGradeRequiredToSign() const
{
	return this->_gradeRequiredToSign;
}

int	AForm::getGradeRequiredToExecute() const
{
	return this->_gradeRequiredToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeRequiredToSign)
	{
		this->_isSigned = true;
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &ofs, AForm &form)
{
	ofs << "Form \"" << form.getName() << std::endl
		<< "  Signed: " << (form.getIsSigned() ? "yes" : "no") << "\n"
		<< "  Grade required to sign:	" << form.getGradeRequiredToSign() << "\n"
		<< "  Grade required to execute: " << form.getGradeRequiredToExecute();
	return ofs;
}
