#include "Cure.hpp"

Cure::Cure( void )
	: AMateria("cure"),
	_type("cure")
{
	std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure( const Cure &other )
	: AMateria(other),
	_type("cure")
{
	std::cout << "Cure copy constructor" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor" << std::endl;
}

Cure & Cure::operator=( const Cure &other)
{
	if (this != &other)
	{

	}
	std::cout << "Cure copy assignment operator" << std::endl;
	return (*this);
}

std::string const & Cure::getType() const
{
	return (this->_type);
}

AMateria* 	Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *"  << std::endl;;
}
