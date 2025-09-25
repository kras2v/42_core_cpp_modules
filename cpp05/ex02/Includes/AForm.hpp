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

	protected:
		virtual void action() const = 0;

	public:
		AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		AForm(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);

		virtual const std::string	getAdditionalInfo() const = 0;
		bool						getIsSigned() const;
		const std::string			getName() const;
		int							getGradeRequiredToSign() const;
		int							getGradeRequiredToExecute() const;

		int 						checkGrade(int grade) const;
		void 						beSigned(Bureaucrat &bureaucrat);
		void						execute(Bureaucrat const & executor) const;

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

		class FormIsNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const noexcept;
		};
};

std::ostream &operator<<(std::ostream &ofs, AForm &form);

#endif /* FORM_HPP */