#include "ScalarConverter.hpp"

t_types getType(const char *literal)
{
	size_t pos;
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
		if ((literal[pos] == 'f' && literal[pos + 1] != '\0') && literal[pos] != '\0')
			return (NONE);
	}
	catch(const std::exception& e)
	{
		return (DOUBLE);
	}

	ssize_t int_n;
	try
	{
		int_n = std::stoi(literal);
		if (int_n > INT32_MAX || int_n < INT32_MIN)
			return (FLOAT);
	}
	catch(const std::exception& e)
	{
		return (FLOAT);
	}

	if (int_n > 255 || int_n < 0)
		return (INT);
	return (CHAR);
}

void ScalarConverter::convert(const char *literal)
{
	t_types type;
	if (!isdigit(literal[0]) && isprint(literal[0]) && literal[1] == '\0')
	{
		uint8_t char_n = literal[0];
		std::cout << "char: " << literal << std::endl;
		std::cout << "int: " << static_cast<int>(char_n) << std::endl;

		if (char_n - static_cast<int>(char_n) == 0)
		{
			std::cout << "float: " << char_n << ".0f" << std::endl;
			std::cout << "double: " << char_n << ".0" << std::endl;
		}
		else
		{
			std::cout << "float: " << char_n << "f" << std::endl;
			std::cout << "double: " << char_n << std::endl;
		}
		return ;
	}
	
	type = getType(literal);
	if (type > CHAR)
		std::cout << "char: impossible" << std::endl;

	if (type > INT)
		std::cout << "int: impossible" << std::endl;

	if (type > FLOAT)
		std::cout << "float: impossible" << std::endl;

	if (type > DOUBLE)
		std::cout << "double: impossible" << std::endl;

	if (type == CHAR)
	{
		uint8_t char_n = std::stoi(literal);
		if (isprint(char_n))
			std::cout << "char: " << static_cast<char>(std::stoi(literal)) << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}

	if (type <= INT)
		std::cout << "int: " << static_cast<int>(std::stoi(literal)) << std::endl;

	if (type <= FLOAT)
	{
		float float_n = std::stof(literal);
		if (float_n - static_cast<int>(float_n) == 0)
			std::cout << "float: " << float_n << ".0f" << std::endl;
		else
			std::cout << "float: " << float_n << "f" << std::endl;
	}

	if (type <= DOUBLE)
	{
		float double_n = std::stod(literal);
		if (double_n - static_cast<int>(double_n) == 0)
			std::cout << "double: " << double_n << ".0" << std::endl;
		else
			std::cout << "double: " << double_n << std::endl;
	}
}
