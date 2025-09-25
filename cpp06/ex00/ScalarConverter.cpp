#include "ScalarConverter.hpp"

ScalarConverter::t_types ScalarConverter::getType(const char *literal)
{
	size_t pos;
	double double_n;
	try
	{
		double_n = std::stod(literal, &pos);
		if (literal[pos] != '\0' && literal[pos] != 'f')
			return (NONE);
	}
	catch(const std::exception& e)
	{
		return (NONE);
	}

	float float_n;
	try
	{
		float_n = std::stof(literal, &pos);
		std::cout << literal[pos] << std::endl;
		if ((literal[pos] == 'f' && literal[pos + 1] != '\0') || literal[pos] != '\0')
			return (NONE);
	}
	catch(const std::exception& e)
	{
		return (DOUBLE);
	}

	ssize_t int_n;
	try
	{
		int_n = std::stol(literal);
		if (int_n > INT32_MAX || int_n < INT32_MIN)
			return (FLOAT);
	}
	catch(const std::exception& e)
	{
		return (FLOAT);
	}

	if (int_n > 255 || int_n < 0)
		return (INT);
	else if (!isprint(int_n))
		return (NON_PRINT_CHAR);
	return (CHAR);
}

void ScalarConverter::convert(const char *literal)
{
	t_types type;
	if (isprint(literal[0]) && literal[1] == '\0')
	{
		float fl = literal[0];
		if (isprint(fl))
			std::cout << "char: " << static_cast<char>(fl) << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(fl) << std::endl;
		if (fl - static_cast<int>(fl) == 0)
			std::cout << "float: " << fl << ".0f" << std::endl;
		else
			std::cout << "float: " << fl << "f" << std::endl;

		if (fl - static_cast<int>(fl) == 0)
			std::cout << "double: " << fl << ".0" << std::endl;
		else
			std::cout << "double: " << fl << std::endl;
		return ;
	}
	
	type = getType(literal);
	std::cout << "TYPE: " << type << std::endl;
	if (type == NONE || type == DOUBLE || type == FLOAT || type == INT)
		std::cout << "char: impossible" << std::endl;

	if (type == NONE || type == DOUBLE || type == FLOAT)
		std::cout << "int: impossible" << std::endl;

	if (type == NONE || type == DOUBLE)
		std::cout << "float: impossible" << std::endl;

	if (type == NONE)
		std::cout << "double: impossible" << std::endl;

	if (type == NON_PRINT_CHAR)
		std::cout << "char: Non displayable" << std::endl;

	if (type == CHAR)
		std::cout << "char: " << static_cast<char>(std::stod(literal)) << std::endl;

	if (type == INT || type == NON_PRINT_CHAR || type == CHAR)
		std::cout << "int: " << static_cast<int>(std::stod(literal)) << std::endl;

	if (type == DOUBLE || type == FLOAT || type == INT || type == CHAR || type == NON_PRINT_CHAR)
	{
		float fl = std::stod(literal);
		if (type != DOUBLE)
		{
			if (fl - static_cast<int>(fl) == 0)
				std::cout << "float: " << fl << ".0f" << std::endl;
			else
				std::cout << "float: " << fl << "f" << std::endl;
		}

		if (fl - static_cast<int>(fl) == 0)
			std::cout << "double: " << fl << ".0" << std::endl;
		else
			std::cout << "double: " << fl << std::endl;
	}
}
