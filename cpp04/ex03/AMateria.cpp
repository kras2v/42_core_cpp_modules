#include "AMateria.hpp"

AMateria::AMateria( void ) = default;

AMateria::AMateria( const AMateria &other ) = default;

AMateria::AMateria( std::string const & type ) : _type(type)
{
	std::cout << "AMateria parametriezd constructor" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor" << std::endl;
}

AMateria & AMateria::operator=( const AMateria &other)
{
	if (this != &other)
	{
		
	}
	std::cout << "AMateria copy assignment operator" << std::endl;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	if (this->_type == "ice")
	{
		std::cout << "* shoots an ice bolt at " << target.getName() << " *";
	}
	else if (this->_type == "cure")
	{
		std::cout << "* heals " << target.getName() << "’s wounds *";
	}
}