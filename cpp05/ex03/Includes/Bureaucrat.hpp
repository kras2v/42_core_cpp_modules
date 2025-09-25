#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define HIGHEST 1
# define LOWEST 150

# include <string>
# include <iostream>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);

		Bureaucrat(const std::string name, int grade);
		const std::string &	getName() const;
		int 				getGrade() const;

		void				increment();
		void				decrement();
		void				checkGrade(int grade) const;

		bool				signForm(AForm &form);

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

std::ostream &operator<<(std::ostream &ofs, Bureaucrat &bur);

#endif /* BUREAUCRAT_HPP */
