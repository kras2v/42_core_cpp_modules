#ifndef FORM_HPP
# define FORM_HPP

# define HIGHEST 1
# define LOWEST 150

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class AForm
{
	private:
		bool				_isSigned = false;
		const std::string	_name;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExecute;

	public:
		AForm();
		AForm(const AForm &other);
		AForm(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		bool				getIsSigned() const;
		const std::string	getName() const;
		int					getGradeRequiredToSign() const;
		int					getGradeRequiredToExecute() const;

		int 				checkGrade(int grade) const;
		void 				beSigned(Bureaucrat &bureaucrat);
		virtual void 		beExecuted(Bureaucrat &bureaucrat) = 0;

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

std::ostream &operator<<(std::ostream &ofs, AForm &form);

#endif /* FORM_HPP */