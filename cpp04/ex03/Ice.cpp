#include "Ice.hpp"

Ice::Ice( void )
	: AMateria("ice"),
	_type("ice")
{
	std::cout << "Ice default constructor" << std::endl;
}

Ice::Ice( const Ice &other )
	: AMateria(other),
	_type("ice")
{
	*this = other;
	std::cout << "Ice copy constructor" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor" << std::endl;
}

Ice & Ice::operator=( const Ice &other)
{
	if (this != &other)
	{

	}
	std::cout << "Ice copy assignment operator" << std::endl;
	return (*this);
}

std::string const & Ice::getType() const
{
	return (this->_type);
}

AMateria* 	Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
