#include "Animal.hpp"

Animal::Animal( void ) : _type("Animal")
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

Animal::Animal( const Animal &other )
{	
	std::cout << "Animal copy constructor" << std::endl;
	*this = other;
}

Animal& Animal::operator=( const Animal &other)
{
	if (this != &other)
	{
		this->setType(other.getType());
	}
	std::cout << "Animal copy assignment operator" << std::endl;
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