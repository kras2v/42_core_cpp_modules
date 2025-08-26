#include "Cure.hpp"

Cure::Cure( void )
	: AMateria("cure"),
	_type("cure")
{
	#ifndef DEBUG
		std::cout << "Cure default constructor" << std::endl;
	#endif
}

Cure::Cure( const Cure &other )
	: AMateria(other),
	_type("cure")
{
	#ifndef DEBUG
		std::cout << "Cure copy constructor" << std::endl;
	#endif
}

Cure::~Cure()
{
	#ifndef DEBUG
		std::cout << "Cure destructor" << std::endl;
	#endif
}

Cure & Cure::operator=( const Cure &other)
{
	(void)other;
	#ifndef DEBUG
		std::cout << "Cure copy assignment operator" << std::endl;
	#endif
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
