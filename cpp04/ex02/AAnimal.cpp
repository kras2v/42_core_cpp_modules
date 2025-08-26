#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : _type("Animal")
{
	#ifndef DEBUG
		std::cout << "AAnimal default constructor" << std::endl;
	#endif
}

AAnimal::AAnimal ( std::string type ) : _type(type)
{
	#ifndef DEBUG
		std::cout << "AAnimal parametrized constructor" << std::endl;
	#endif
}

AAnimal::~AAnimal()
{
	#ifndef DEBUG
		std::cout << "AAnimal destructor" << std::endl;
	#endif
}

AAnimal::AAnimal( const AAnimal &other )
{	
	*this = other;
	#ifndef DEBUG
		std::cout << "AAnimal copy constructor" << std::endl;
	#endif
}

AAnimal& AAnimal::operator=( const AAnimal &other)
{
	if (this != &other)
	{
		this->setType(other.getType());
	}
	#ifndef DEBUG
		std::cout << "AAnimal copy assignment operator" << std::endl;
	#endif
	return (*this);
}

void AAnimal::makeSound( void ) const
{
	std::cout << "*animal sound*" << std::endl;
}

const std::string &AAnimal::getType( void ) const
{
	return (this->_type);
}

void AAnimal::setType( const std::string &type )
{
	this->_type = type;
}