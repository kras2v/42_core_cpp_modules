#ifndef PRN_HPP
# define PRN_HPP

# include <iostream>
# include <stack>

class RPN
{
	enum sign
	{
		ADDITION = '+',
		SUBTRACTION = '-',
		MULTIPLICATION = '*',
		DIVISION = '/'
	};

	private:
		static const size_t minLenght;

		static void isEmpty(std::string &expression);
		static void hasLeadingTrailingSpaces(std::string &expression);
		static void isTooShort(std::string &expression);
		static void checkNumber(std::string &expression, std::stack<int> &stack);

		static bool issign(char c);

		RPN(const RPN &other) = delete;
		RPN & operator=(const RPN &other) = delete;
		RPN() = delete;
		~RPN() = delete;

	public:
		static int calculate(std::string &expression);

		class RPNException : public std::exception
		{
			private:
				std::string _message;
			
			public:
				RPNException(const std::string& message);
				virtual const char* what() const throw();
		};
};

#endif /* PRN_HPP */