#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>

class ScalarConverter
{
	private:
		typedef enum e_types
		{
			CHAR,
			NON_PRINT_CHAR,
			INT,
			FLOAT,
			DOUBLE,
			NONE
		} t_types;

		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter &other) = delete;
		virtual ~ScalarConverter() = 0;
		ScalarConverter &operator=(const ScalarConverter &other) = delete;

		static void charType(const char *literal);
		static void intType(const char *literal);
		static void floatType(const char *literal);
		static void doubleType(const char *literal);
		static t_types getType(const char *literal);

	public:
		static void convert(const char *literal);
};

#endif /* SCALAR_CONVERTER_HPP */