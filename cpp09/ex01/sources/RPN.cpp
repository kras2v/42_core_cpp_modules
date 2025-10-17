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

bool RPN::isEmpty(std::string &expression)
{
	return expression.empty();
}

bool RPN::hasLeadingTrailingSpaces(std::string &expression)
{
	return isspace(expression.front())
	|| isspace(expression.back());
}

bool RPN::isTooShort(std::string &expression)
{
	return expression.length() < minLenght;
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

	if (isEmpty(expression) || hasLeadingTrailingSpaces(expression)
		|| isTooShort(expression))
		throw std::runtime_error("Error");

	while (expression.front())
	{
		if (!RPN::issign(expression.front()))
			checkNumber(expression, stack);
		else
		{
			//!TODO: Create custom exceptions
			if (stack.size() < 2)
				throw std::runtime_error("Error");

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
						throw std::runtime_error("Error");
					stack.push(second / first);
					break;

				default:
				break;
			}
		}

		expression = expression.erase(0, 1);
		if ((expression.begin() != expression.end())
			&& !isspace(expression.front()))
			throw std::runtime_error("Error");
		expression = expression.erase(0, 1);
	}

	if (stack.size() != 1)
		throw std::runtime_error("Error");
	return stack.top();
}
