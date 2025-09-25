#include "Form.hpp"

Form::Form():
	_name("default"),
	_gradeRequiredToSign(5),
	_gradeRequiredToExecute(5)
{
	#ifdef DEBUG
		std::cout << "Form default constructor" << std::endl;
	#endif
}

Form::Form(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute) :
	_name(name),
	_gradeRequiredToSign(checkGrade(gradeRequiredToSign)),
	_gradeRequiredToExecute(checkGrade(gradeRequiredToExecute))
{
	#ifdef DEBUG
		std::cout << "Form parametrized constructor" << std::endl;
	#endif
}

Form::~Form()
{
	#ifdef DEBUG
		std::cout << "Form default destructor" << std::endl;
	#endif
}

int Form::checkGrade(int grade) const
{
	if (grade < HIGHEST)
	{
		throw Form::GradeTooHighException();
	}
	if (grade > LOWEST)
	{
		throw Form::GradeTooLowException();
	}
	return (grade);
}

Form::Form(const Form &other) :
	_isSigned(other._isSigned),
	_name(other._name),
	_gradeRequiredToSign(other._gradeRequiredToSign),
	_gradeRequiredToExecute(other._gradeRequiredToExecute)
{
	#ifdef DEBUG
		std::cout << "Form copy constructor" << std::endl;
	#endif
}

Form &Form::operator=(const Form &other)
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

const char *Form::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low!");
}

bool	Form::getIsSigned() const
{
	return this->_isSigned;
}

const std::string	Form::getName() const
{
	return this->_name;
}

int	Form::getGradeRequiredToSign() const
{
	return this->_gradeRequiredToSign;
}

int	Form::getGradeRequiredToExecute() const
{
	return this->_gradeRequiredToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeRequiredToSign)
	{
		this->_isSigned = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &ofs, Form &form)
{
	ofs << "Form \"" << form.getName() << std::endl
		<< "  Signed: " << (form.getIsSigned() ? "yes" : "no") << "\n"
		<< "  Grade required to sign:\t" << form.getGradeRequiredToSign() << "\n"
		<< "  Grade required to execute:\t" << form.getGradeRequiredToExecute();
	return ofs;
}
