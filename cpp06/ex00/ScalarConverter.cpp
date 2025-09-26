#include "ScalarConverter.hpp"

t_types getType(const char *literal)
{
	if (!isdigit(literal[0]) && isprint(literal[0]) && literal[1] == '\0')
		return (CHAR);

	size_t pos;
	try
	{
		std::stoi(literal, &pos);
		if (literal[pos] == '\0')
			return (INT);
	}
	catch(const std::exception& e) { }

	try
	{
		std::stod(literal, &pos);
		if (literal[pos] != '\0' && literal[pos] != 'f')
			return (NONE);
	}
	catch(const std::exception& e)
	{
		return (NONE);
	}

	try
	{
		std::stof(literal, &pos);
		if ((literal[pos] == 'f' && literal[pos + 1] == '\0'))
			return (FLOAT);
		if (literal[pos] != '\0')
			return (NONE);
	}
	catch(const std::exception& e) { }
	return (DOUBLE);
}

void printCharLiteral(int int_n)
{
	if (int_n < 0 || int_n > 127)
	{
		std::cout << "char: impossible" << std::endl;
	}
	else if (!isprint(int_n))
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	else
	{
		std::cout << "char: '" << static_cast<char>(int_n) << "'" << std::endl;
	}
}

void printInFloatPointFormat(double d)
{
	if (d <= INT32_MAX && d >= INT32_MIN)
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	else
		std::cout << "double: " << std::scientific << std::setprecision(1) << d << std::endl;
}

void printInFloatPointFormat(float f)
{
	if (f <= INT32_MAX && f >= INT32_MIN)
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	else
		std::cout << "float: " << std::scientific << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::convert(const char *literal)
{
	switch (getType(literal))
	{
		case CHAR:
		{
			std::cout << "char: '" << literal << "'" << std::endl;
			std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
			std::cout << "float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(literal[0]) << ".0" << std::endl;
			break;
		}

		case INT:
		{
			int int_n = std::stoi(literal);
			printCharLiteral(int_n);
			std::cout << "int: " << int_n << std::endl;
			printInFloatPointFormat(static_cast<float>(int_n));
			printInFloatPointFormat(static_cast<double>(int_n));
			break;
		}

		case FLOAT:
		{
			float float_n = std::stof(literal);

			try
			{
				if (float_n > static_cast<double>(INT32_MAX) || float_n < static_cast<double>(INT32_MIN))
					throw std::exception();

				std::stoi(literal);
				printCharLiteral(static_cast<int>(float_n));
				std::cout << "int: " << static_cast<int>(float_n) << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
			}

			printInFloatPointFormat(float_n);
			printInFloatPointFormat(static_cast<double>(float_n));
			break;
		}

		case DOUBLE:
		{
			double double_n = std::stod(literal);

			try
			{
				std::stoi(literal);
				printCharLiteral(static_cast<int>(double_n));
				std::cout << "int: " << static_cast<int>(double_n) << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
			}

			try
			{
				std::stof(literal);
				printInFloatPointFormat(static_cast<float>(double_n));
			}
			catch(const std::exception& e)
			{
				std::cerr << "float: impossible" << '\n';
			}
			printInFloatPointFormat(double_n);
			break;
		}

		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			break;
	}
}
