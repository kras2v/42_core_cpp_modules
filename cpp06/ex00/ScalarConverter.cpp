#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() = delete;
ScalarConverter::ScalarConverter(const ScalarConverter &other) = delete;
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) = delete;
ScalarConverter::~ScalarConverter() = delete;

void ScalarConverter::charType(const std::string literal)
{
	try
	{
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void ScalarConverter::intType(const std::string literal)
{

}

void ScalarConverter::floatType(const std::string literal)
{

}

void ScalarConverter::doubleType(const std::string literal)
{

}

void ScalarConverter::convert(const std::string literal)
{
	charType(literal);
	intType(literal);
	floatType(literal);
	doubleType(literal);
}
