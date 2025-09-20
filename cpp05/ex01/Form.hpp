#ifndef FORM_HPP
# define FORM_HPP

# define HIGHEST 1
# define LOWEST 150

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	private:
		bool				_isSigned = false;
		const std::string	_name;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExecute;

	public:
		Form();
		Form(const Form &other);
		Form(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
		Form &operator=(const Form &other);
		~Form();

		bool				getIsSigned() const;
		const std::string	getName() const;
		int					getGradeRequiredToSign() const;
		int					getGradeRequiredToExecute() const;

		int 				checkGrade(int grade) const;
		void 				beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const noexcept;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const noexcept;
		};
};

std::ostream &operator<<(std::ostream &ofs, Form &form);

#endif /* FORM_HPP */