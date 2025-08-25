#include "Dog.hpp"

Dog::Dog( void ) : _type("Dog")
{
	std::cout << "Dog default constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

Dog::Dog( const Dog &other ) : Animal(other)
{	
	std::cout << "Dog copy constructor" << std::endl;
	*this = other;
}

Dog & Dog::operator=( const Dog &other)
{
	Animal::operator=(other);
	std::cout << "Dog copy assignment operator" << std::endl;
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "bark bark bark" << std::endl;
}

const std::string &Dog::getType( void ) const
{
	return (this->_type);
}

void Dog::setType( const std::string &type )
{
	this->_type = type;
}