#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <cmath>

typedef enum e_types
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
} t_types;

class ScalarConverter
{
	private:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter &other) = delete;
		virtual ~ScalarConverter() = 0;
		ScalarConverter &operator=(const ScalarConverter &other) = delete;

	public:
		static void convert(const char *literal);
};

#endif /* SCALAR_CONVERTER_HPP */