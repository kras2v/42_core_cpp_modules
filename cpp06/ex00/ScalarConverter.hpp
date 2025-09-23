#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter(/* args */);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		static void charType(const std::string literal);
		static void intType(const std::string literal);
		static void floatType(const std::string literal);
		static void doubleType(const std::string literal);

	public:
		static void convert(const std::string literal);
};

#endif /* SCALAR_CONVERTER_HPP */