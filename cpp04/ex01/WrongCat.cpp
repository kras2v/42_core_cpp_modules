#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
	this->_brain = new Brain;
	#ifndef DEBUG
		std::cout << "WrongCat default constructor" << std::endl;
	#endif
}

WrongCat::~WrongCat()
{
	delete this->_brain;
	#ifndef DEBUG
		std::cout << "WrongCat destructor" << std::endl;
	#endif
}

WrongCat::WrongCat( const WrongCat &other ) : WrongAnimal(other), _brain(nullptr)
{	
	*this = other;
	#ifndef DEBUG
		std::cout << "WrongCat copy constructor" << std::endl;
	#endif
}

WrongCat & WrongCat::operator=( const WrongCat &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		if (this->_brain != nullptr)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	#ifndef DEBUG
		std::cout << "WrongCat copy assignment operator" << std::endl;
	#endif
	return (*this);
}

void WrongCat::makeSound( void ) const
{
	std::cout << "meow meow meow" << std::endl;
}
