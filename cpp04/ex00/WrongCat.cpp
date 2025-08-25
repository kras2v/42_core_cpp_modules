#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : _type("WrongCat")
{
	std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

WrongCat::WrongCat( const WrongCat &other ) : AWrongAnimal(other)
{	
	std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat & WrongCat::operator=( const WrongCat &other)
{
	if (this != &other)
	{
		AWrongAnimal::operator=(other);
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