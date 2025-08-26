#include "AWrongAnimal.hpp"

AWrongAnimal::AWrongAnimal( void ) : _type("WrongAnimal")
{
	#ifndef DEBUG
		std::cout << "Wrong animal default constructor" << std::endl;
	#endif
}

AWrongAnimal::AWrongAnimal( std::string type ) : _type(type)
{
	#ifndef DEBUG
		std::cout << "Wrong animal param constructor" << std::endl;
	#endif
}

AWrongAnimal::~AWrongAnimal()
{
	#ifndef DEBUG
		std::cout << "Wrong animal destructor" << std::endl;
	#endif
}

AWrongAnimal::AWrongAnimal( const AWrongAnimal &other )
{	
	*this = other;
	#ifndef DEBUG
		std::cout << "Wrong animal copy constructor" << std::endl;
	#endif
}

AWrongAnimal & AWrongAnimal::operator=( const AWrongAnimal &other)
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

void AWrongAnimal::makeSound( void ) const
{
	std::cout << "*Wrong animal sound*" << std::endl;
}

const std::string &AWrongAnimal::getType( void ) const
{
	return (this->_type);
}

void AWrongAnimal::setType( const std::string &type )
{
	this->_type = type;
}