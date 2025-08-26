#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	#ifndef DEBUG
		std::cout << "Dog default constructor" << std::endl;
	#endif
}

Dog::~Dog()
{
	#ifndef DEBUG
		std::cout << "Dog destructor" << std::endl;
	#endif
}

Dog::Dog( const Dog &other ) : Animal(other)
{	
	#ifndef DEBUG
		std::cout << "Dog copy constructor" << std::endl;
	#endif
	*this = other;
}

Dog & Dog::operator=( const Dog &other)
{
	Animal::operator=(other);
	#ifndef DEBUG
		std::cout << "Dog copy assignment operator" << std::endl;
	#endif
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "bark bark bark" << std::endl;
}
