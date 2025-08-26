#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal")
{
	#ifndef DEBUG
		std::cout << "Wrong animal default constructor" << std::endl;
	#endif
}

WrongAnimal::WrongAnimal( std::string type ) : _type(type)
{
	#ifndef DEBUG
		std::cout << "Wrong animal default constructor" << std::endl;
	#endif
}

WrongAnimal::~WrongAnimal()
{
	#ifndef DEBUG
		std::cout << "Wrong animal destructor" << std::endl;
	#endif
}

WrongAnimal::WrongAnimal( const WrongAnimal &other )
{	
	#ifndef DEBUG
		std::cout << "Wrong animal copy constructor" << std::endl;
	#endif
	*this = other;
}

WrongAnimal & WrongAnimal::operator=( const WrongAnimal &other)
{
	if (this != &other)
	{
		this->setType(other.getType());
	}
	#ifndef DEBUG
		std::cout << "Wrong animal copy assignment operator" << std::endl;
	#endif
	return (*this);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "*Wrong animal sound*" << std::endl;
}

const std::string &WrongAnimal::getType( void ) const
{
	return (this->_type);
}

void WrongAnimal::setType( const std::string &type )
{
	this->_type = type;
}