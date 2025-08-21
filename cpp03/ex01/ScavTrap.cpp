#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "ScavTrap copy constructor" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap custom constructor" << std::endl;
}

void ScavTrap::guardGate( void )
{
	std::cout << " ScavTrap is now in Gate keeper mode." << std::endl;
}
