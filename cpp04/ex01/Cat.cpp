#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	this->_brain = new Brain();
	#ifndef DEBUG
		std::cout << "Cat default constructor" << std::endl;
	#endif
}

Cat::~Cat( void )
{
	delete this->_brain;
	#ifndef DEBUG
		std::cout << "Cat destructor" << std::endl;
	#endif
}

Cat::Cat( const Cat &other ) : Animal(other), _brain(nullptr)
{
	*this = other;
	#ifndef DEBUG
		std::cout << "Cat copy constructor" << std::endl;
	#endif
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
	#ifndef DEBUG
		std::cout << "Cat copy assignment operator" << std::endl;
	#endif
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "meow meow meow" << std::endl;
}

const Brain& Cat::getBrain ( void ) const
{
	return (*this->_brain);
}

void Cat::setBrain ( const Brain &Brain )
{
	*this->_brain = Brain;
}
