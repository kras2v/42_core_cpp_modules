#include "AWrongAnimal.hpp"

AWrongAnimal::AWrongAnimal( void ) : _type("WrongAnimal")
{
	std::cout << "Wrong animal default constructor" << std::endl;
}

AWrongAnimal::~AWrongAnimal()
{
	std::cout << "Wrong animal destructor" << std::endl;
}

AWrongAnimal::AWrongAnimal( const AWrongAnimal &other )
{	
	*this = other;
	std::cout << "Wrong animal copy constructor" << std::endl;
}

AWrongAnimal & AWrongAnimal::operator=( const AWrongAnimal &other)
{
	if (this != &other)
	{
		this->setType(other.getType());
	}
	std::cout << "Wrong animal copy assignment operator" << std::endl;
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