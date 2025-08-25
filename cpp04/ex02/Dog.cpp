#include "Dog.hpp"

Dog::Dog( void ) : _type("Dog")
{
	this->_brain = new Brain;
	std::cout << "Dog default constructor" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor" << std::endl;
}

Dog::Dog( const Dog &other ) : AAnimal(other), _brain(nullptr)
{	
	*this = other;
	std::cout << "Dog copy constructor" << std::endl;
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