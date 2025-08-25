#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : _type("WrongCat")
{
	this->_brain = new Brain;
	std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::~WrongCat()
{
	delete this->_brain;
	std::cout << "WrongCat destructor" << std::endl;
}

WrongCat::WrongCat( const WrongCat &other ) : AWrongAnimal(other), _brain(nullptr)
{	
	*this = other;
	std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat & WrongCat::operator=( const WrongCat &other)
{
	if (this != &other)
	{
		AWrongAnimal::operator=(other);
		if (this->_brain != nullptr)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	std::cout << "WrongCat copy assignment operator" << std::endl;
	return (*this);
}

void WrongCat::makeSound( void ) const
{
	std::cout << "meow meow meow" << std::endl;
}

const std::string &WrongCat::getType( void ) const
{
	return (this->_type);
}

void WrongCat::setType( const std::string &type )
{
	this->_type = type;
}