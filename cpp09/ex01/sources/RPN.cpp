#include <RPN.hpp>

const size_t RPN::minLenght = 5;

bool RPN::issign(char c)
{
	return (   c == ADDITION
			|| c == SUBTRACTION
			|| c == MULTIPLICATION
			|| c == DIVISION
		);
}

void RPN::isEmpty(std::string &expression)
{
	if (expression.empty())
		throw RPN::RPNException("expression is empty");
}

void RPN::hasLeadingTrailingSpaces(std::string &expression)
{
	if (isspace(expression.front()) || isspace(expression.back()))
		throw RPN::RPNException("has trailing or leading spaces");
}

void RPN::isTooShort(std::string &expression)
{
	if (expression.length() < minLenght)
		throw RPN::RPNException("expression is too short");
}

void RPN::checkNumber(std::string &expression, std::stack<int> &stack)
{
	size_t pos;
	int numb = std::stoi(expression, &pos, 10);

	if (pos != 1)
		throw std::runtime_error("Error");

	stack.push(numb);
}

int RPN::calculate(std::string &expression)
{
	std::stack<int> stack;

	isEmpty(expression);
	hasLeadingTrailingSpaces(expression);
	isTooShort(expression);

	while (expression.front())
	{
		if (!RPN::issign(expression.front()))
			checkNumber(expression, stack);
		else
		{
			if (stack.size() < 2)
				throw RPN::RPNException("expression has a wrong format");

			stack.push(expression.front());

			int sign = stack.top();
			stack.pop();

			int first = stack.top();
			stack.pop();

			int second = stack.top();
			stack.pop();

			switch (sign)
			{
				case '+':
					stack.push(second + first);
					break;

				case '-':
					stack.push(second - first);
					break;

				case '*':
					stack.push(second * first);
					break;

				case '/':
					if (first == 0)
						throw RPN::RPNException("expression has a wrong format");
					stack.push(second / first);
					break;

				default:
				break;
			}
		}

		expression = expression.erase(0, 1);
		if ((expression.begin() != expression.end())
			&& !isspace(expression.front()))
				throw RPN::RPNException("expression has a wrong format");
		expression = expression.erase(0, 1);
	}

	if (stack.size() != 1)
		throw RPN::RPNException("expression has a wrong format");
	return stack.top();
}

RPN::RPNException::RPNException(const std::string& message)
	: _message(message) {}

const char* RPN::RPNException::what() const throw()
{
	return _message.c_str();
}