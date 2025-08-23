#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap()
{
	std::cout << "DiamondTrap " << this->ScavTrap::getName() << " default constructor" << std::endl;
	this->FragTrap::setHitPoint(this->FragTrap::getDefaultHitPoint());
	this->ScavTrap::setEnergyPoint(this->ScavTrap::getDefaultEnergyPoint());
	this->FragTrap::setAttackDamage(this->FragTrap::getDefaultAttackDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	:ClapTrap(other),
	FragTrap(other),
	ScavTrap(other)
{
	std::cout << "DiamondTrap " << this->ScavTrap::getName() << " copy constructor" << std::endl;
	this->FragTrap::setHitPoint(this->FragTrap::getDefaultHitPoint());
	this->ScavTrap::setEnergyPoint(this->ScavTrap::getDefaultEnergyPoint());
	this->FragTrap::setAttackDamage(this->FragTrap::getDefaultAttackDamage());
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"),
	FragTrap(name + "_clap_name"),
	ScavTrap(name + "_clap_name"),
	_name(name)
{
	std::cout << "DiamondTrap " << this->ScavTrap::getName() << " custom constructor" << std::endl;
	this->FragTrap::setHitPoint(this->FragTrap::getDefaultHitPoint());
	this->ScavTrap::setEnergyPoint(this->ScavTrap::getDefaultEnergyPoint());
	this->FragTrap::setAttackDamage(this->FragTrap::getDefaultAttackDamage());
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->ScavTrap::getName() << " destructor" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy assignment " << this->ScavTrap::getName() << " operator called" << std::endl;
	if (this != &other)
	{
		ScavTrap::operator=(other);
	}
	return (*this);
}

void DiamondTrap::showStatistics( void )
{
	const int width = 50;
	std::cout << std::endl;
	std::cout << std::string(width, '=') << std::endl;
	std::cout << "| " << std::setw(width - 4) << std::left << ("DiamondTrap " + this->getName() + " statistics:") << " |" << std::endl;
	std::cout << std::string(width, '-') << std::endl;
	std::cout << "| " << std::setw(width - 4) << std::left << ("Hit points:      " + std::to_string(this->getHitPoint())) << " |" << std::endl;
	std::cout << "| " << std::setw(width - 4) << std::left << ("Energy points:   " + std::to_string(this->getEnergyPoint())) << " |" << std::endl;
	std::cout << "| " << std::setw(width - 4) << std::left << ("Attack damage:   " + std::to_string(this->getAttackDamage())) << " |" << std::endl;
	std::cout << std::string(width, '=') << std::endl << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Who am i?.. Hm... I'm a Diamond Trap. My name is " << this->getName() << std::endl
	<< "but wait.. I'm also a " << this->ScavTrap::getName() << ".... who.. am.. i?.." << std::endl;
}

std::string DiamondTrap::getName() const
{
	return (this->_name);
}

void DiamondTrap::setName( const std::string name )
{
	this->_name = name;
}