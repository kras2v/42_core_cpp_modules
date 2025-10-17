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

		static bool isEmpty(std::string &expression);
		static bool hasLeadingTrailingSpaces(std::string &expression);
		static bool isTooShort(std::string &expression);
		static void checkNumber(std::string &expression, std::stack<int> &stack);

		static bool issign(char c);

		RPN(const RPN &other) = delete;
		RPN & operator=(const RPN &other) = delete;
		RPN() = delete;
		~RPN() = delete;

	public:
		static int calculate(std::string &expression);
};

#endif /* PRN_HPP */