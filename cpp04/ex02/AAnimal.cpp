#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : _type("Animal")
{
	std::cout << "AAnimal default constructor" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor" << std::endl;
}

AAnimal::AAnimal( const AAnimal &other )
{	
	*this = other;
	std::cout << "AAnimal copy constructor" << std::endl;
}

AAnimal& AAnimal::operator=( const AAnimal &other)
{
	if (this != &other)
	{
		this->setType(other.getType());
	}
	std::cout << "AAnimal copy assignment operator" << std::endl;
	return (*this);
}

void AAnimal::makeSound( void ) const
{
	std::cout << "*animal sound*" << std::endl;
}

const std::string &AAnimal::getType( void ) const
{
	return (this->_type);
}

void AAnimal::setType( const std::string &type )
{
	this->_type = type;
}