#include <iostream>
#include <string>
#include "Fixed.hpp"

int main( void ) 
{
	{
		Fixed a( 1234.4321f );
		Fixed const b( 10 );

		std::cout << std::string(60, '-') << std::endl;
		std::cout << "The 6 comparison operators: >, <, >=, <=, ==, and !=." << std::endl;
		std::cout << a << " > " << b << " = " << ((a > b) ? "true": "false") << std::endl;
		std::cout << a << " < " << b << " = " << ((a < b) ? "true": "false") << std::endl;
		std::cout << a << " >= " << b << " = " << ((a >= b) ? "true": "false") << std::endl;
		std::cout << a << " <= " << b << " = " << ((a <= b) ? "true": "false") << std::endl;
		std::cout << a << " == " << b << " = " << ((a == b) ? "true": "false") << std::endl;
		std::cout << a << " != " << b << " = " << ((a != b) ? "true": "false") << std::endl;
	}

	{
		Fixed a( 5.05f );
		Fixed b( 2 );

		std::cout << std::string(60, '-') << std::endl;
		std::cout << "The 4 arithmetic operators: +, -, *, and /." << std::endl;
		std::cout << a << " + " << b << " = " << (a + b) << std::endl;
		std::cout << a << " - " << b << " = " << (a - b) << std::endl;
		std::cout << a << " * " << b << " = " << (a * b) << std::endl;
		std::cout << a << " / " << b << " = " << (a / b) << std::endl;
	}

	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ));

		std::cout << std::string(60, '-') << std::endl;
		std::cout << "The increment:" << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << ++a << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a++ << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		std::cout << std::string(60, '-') << std::endl;
		std::cout << "The decrement:" << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << --a << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a-- << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		std::cout << std::string(60, '-') << std::endl;
		std::cout << "Min and max:" << std::endl;
		std::cout << "max: " << Fixed::max( a, b ) << std::endl;
		std::cout << "min: " << Fixed::min( a, b ) << std::endl;
	}
	return 0;
}