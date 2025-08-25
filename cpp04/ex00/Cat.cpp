#include "Cat.hpp"

Cat::Cat( void ) : _type("Cat")
{
	std::cout << "Cat default constructor" << std::endl;
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor" << std::endl;
}

Cat::Cat( const Cat &other ) : Animal(other)
{	
	std::cout << "Cat copy constructor" << std::endl;
	*this = other;
}

Cat& Cat::operator=( const Cat &other )
{
	Animal::operator=(other);
	std::cout << "Cat copy assignment operator" << std::endl;
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "meow meow meow" << std::endl;
}

const std::string &Cat::getType( void ) const
{
	return (this->_type);
}

void Cat::setType( const std::string &type )
{
	this->_type = type;
}