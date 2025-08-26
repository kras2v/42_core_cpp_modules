#include "AMateria.hpp"

AMateria::AMateria( void ) = default;

AMateria::AMateria( const AMateria &other ) = default;

AMateria::AMateria( std::string const & type ) : _type(type)
{
	#ifndef DEBUG
		std::cout << "AMateria parametriezd constructor" << std::endl;
	#endif
}

AMateria::~AMateria()
{
	#ifndef DEBUG
		std::cout << "AMateria destructor" << std::endl;
	#endif
}

AMateria & AMateria::operator=( const AMateria &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	#ifndef DEBUG
		std::cout << "AMateria copy assignment operator" << std::endl;
	#endif
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	this->use(target);
}