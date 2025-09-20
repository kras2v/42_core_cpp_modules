#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(75)
{
	#ifdef DEBUG
		std::cout << "Bureaucrat default constructor" << std::endl;
	#endif
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	checkGrade(grade);
	this->_grade = grade;
	#ifdef DEBUG
		std::cout << "Bureaucrat parametrized constructor" << std::endl;
	#endif
}

Bureaucrat::~Bureaucrat()
{
	#ifdef DEBUG
		std::cout << "Bureaucrat destructor" << std::endl;
	#endif
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
	#ifdef DEBUG
		std::cout << "Bureaucrat copy constructor" << std::endl;
	#endif
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	#ifdef DEBUG
		std::cout << "Bureaucrat assignment operator" << std::endl;
	#endif
	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::increment()
{
	checkGrade(this->_grade - 1);
	this->_grade--;
}

void Bureaucrat::decrement()
{
	checkGrade(this->_grade + 1);
	this->_grade++;
}

void Bureaucrat::checkGrade(int grade) const
{
	if (grade < HIGHEST)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > LOWEST)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

bool Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed \"" << form.getName() << "\"" << std::endl;
		return (true);
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn’t sign form \"" << form.getName() << "\" because " << e.what() << std::endl;
	}
	return (false);
}

std::ostream &operator<<(std::ostream &ofs, Bureaucrat &bur)
{
	ofs << bur.getName() << ", bureaucrat grade " << bur.getGrade() << std::endl;
	return ofs;
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low!");
}


