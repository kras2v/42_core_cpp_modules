#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	#ifndef DEBUG
		std::cout << "Cat default constructor" << std::endl;
	#endif
}

Cat::~Cat( void )
{
	#ifndef DEBUG
		std::cout << "Cat destructor" << std::endl;
	#endif
}

Cat::Cat( const Cat &other ) : Animal(other)
{	
	#ifndef DEBUG
		std::cout << "Cat copy constructor" << std::endl;
	#endif
	*this = other;
}

Cat& Cat::operator=( const Cat &other )
{
	Animal::operator=(other);
	#ifndef DEBUG
		std::cout << "Cat copy assignment operator" << std::endl;
	#endif
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "meow meow meow" << std::endl;
}
