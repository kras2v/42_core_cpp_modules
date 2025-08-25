#include "Cat.hpp"

Cat::Cat( void ) : _type("Cat")
{
	this->_brain = new Brain();
	std::cout << "Cat default constructor" << std::endl;
}

Cat::~Cat( void )
{
	delete this->_brain;
	std::cout << "Cat destructor" << std::endl;
}

Cat::Cat( const Cat &other ) : Animal(other), _brain(nullptr)
{
	*this = other;
	std::cout << "Cat copy constructor" << std::endl;
}

Cat& Cat::operator=( const Cat &other )
{
	if (this != &other)
	{
		Animal::operator=(other);
		if (this->_brain != nullptr)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
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

const Brain& Cat::getBrain ( void ) const
{
	return (*this->_brain);
}

void Cat::setBrain ( const Brain &Brain )
{
	*this->_brain = Brain;
}
