#include "Dog.hpp"

Dog::Dog( void ) : AAnimal("Dog")
{
	this->_brain = new Brain;
	#ifndef DEBUG
		std::cout << "Dog default constructor" << std::endl;
	#endif
}

Dog::~Dog()
{
	delete this->_brain;
	#ifndef DEBUG
		std::cout << "Dog destructor" << std::endl;
	#endif
}

Dog::Dog( const Dog &other ) : AAnimal(other), _brain(nullptr)
{	
	*this = other;
	#ifndef DEBUG
		std::cout << "Dog copy constructor" << std::endl;
	#endif
}

Dog & Dog::operator=( const Dog &other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		if (this->_brain != nullptr)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	#ifndef DEBUG
		std::cout << "Dog copy assignment operator" << std::endl;
	#endif
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "bark bark bark" << std::endl;
}
