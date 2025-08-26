#include "Ice.hpp"

Ice::Ice( void )
	: AMateria("ice"),
	_type("ice")
{
	#ifndef DEBUG
		std::cout << "Ice default constructor" << std::endl;
	#endif
}

Ice::Ice( const Ice &other )
	: AMateria(other),
	_type("ice")
{
	*this = other;
	#ifndef DEBUG
		std::cout << "Ice copy constructor" << std::endl;
	#endif
}

Ice::~Ice()
{
	#ifndef DEBUG
		std::cout << "Ice destructor" << std::endl;
	#endif
}

Ice & Ice::operator=( const Ice &other)
{
	(void)other;
	#ifndef DEBUG
		std::cout << "Ice copy assignment operator" << std::endl;
	#endif
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
