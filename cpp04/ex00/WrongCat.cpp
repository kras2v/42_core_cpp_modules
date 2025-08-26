#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
	#ifndef DEBUG
		std::cout << "WrongCat default constructor" << std::endl;
	#endif
}

WrongCat::~WrongCat()
{
	#ifndef DEBUG
		std::cout << "WrongCat destructor" << std::endl;
	#endif
}

WrongCat::WrongCat( const WrongCat &other ) : WrongAnimal(other)
{	
	#ifndef DEBUG
		std::cout << "WrongCat copy constructor" << std::endl;
	#endif
}

WrongCat & WrongCat::operator=( const WrongCat &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	#ifndef DEBUG
		std::cout << "WrongCat copy assignment operator" << std::endl;
	#endif
	return (*this);
}

void WrongCat::makeSound( void ) const
{
	std::cout << "meow meow meow" << std::endl;
}
