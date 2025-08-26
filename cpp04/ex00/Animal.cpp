#include "Animal.hpp"

Animal::Animal( void ) : _type("Animal")
{
	#ifndef DEBUG
		std::cout << "Animal default constructor" << std::endl;
	#endif
}

Animal::Animal ( std::string type ) : _type(type)
{
	#ifndef DEBUG
		std::cout << "Animal parametrized constructor" << std::endl;
	#endif
}

Animal::~Animal()
{
	#ifndef DEBUG
		std::cout << "Animal destructor" << std::endl;
	#endif
}

Animal::Animal( const Animal &other )
{	
	#ifndef DEBUG
		std::cout << "Animal copy constructor" << std::endl;
	#endif
	*this = other;
}

Animal& Animal::operator=( const Animal &other)
{
	if (this != &other)
	{
		this->setType(other.getType());
	}
	#ifndef DEBUG
		std::cout << "Animal copy assignment operator" << std::endl;
	#endif
	return (*this);
}

void Animal::makeSound( void ) const
{
	std::cout << "*animal sound*" << std::endl;
}

const std::string &Animal::getType( void ) const
{
	return (this->_type);
}

void Animal::setType( const std::string &type )
{
	this->_type = type;
}