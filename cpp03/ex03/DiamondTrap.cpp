#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name("defaultDiamond")
{
	std::cout << "DiamondTrap " << this->getName() << " default constructor" << std::endl;
	this->setHitPoint(this->FragTrap::getDefaultHitPoint());
	this->setEnergyPoint(this->ScavTrap::getDefaultEnergyPoint());
	this->setAttackDamage(this->FragTrap::getDefaultAttackDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	:ClapTrap(other),
	FragTrap(other),
	ScavTrap(other),
	_name(other.getName())
{
	std::cout << "DiamondTrap " << this->getName() << " copy constructor" << std::endl;
	this->setHitPoint(this->FragTrap::getDefaultHitPoint());
	this->setEnergyPoint(this->ScavTrap::getDefaultEnergyPoint());
	this->setAttackDamage(this->FragTrap::getDefaultAttackDamage());
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"),
	FragTrap(name + "_clap_name"),
	ScavTrap(name + "_clap_name"),
	_name(name)
{
	std::cout << "DiamondTrap " << this->getName() << " custom constructor" << std::endl;
	this->setHitPoint(this->FragTrap::getDefaultHitPoint());
	this->setEnergyPoint(this->ScavTrap::getDefaultEnergyPoint());
	this->setAttackDamage(this->FragTrap::getDefaultAttackDamage());
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->getName() << " destructor" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ScavTrap::operator=(other);
	}
	std::cout << "DiamondTrap copy assignment " << this->getName() << " operator called" << std::endl;
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