#include "ScavTrap.hpp"

const unsigned int ScavTrap::_defaultHitPoint = 100;
const unsigned int ScavTrap::_defaultEnergyPoint = 50;
const unsigned int ScavTrap::_defaultAttackDamage = 20;

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap " << this->getName() << " default constructor" << std::endl;
	this->setAttackDamage(_defaultAttackDamage);
	this->setEnergyPoint(_defaultEnergyPoint);
	this->setHitPoint(_defaultHitPoint);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap " << this->getName() << " copy constructor" << std::endl;
	this->setAttackDamage(_defaultAttackDamage);
	this->setEnergyPoint(_defaultEnergyPoint);
	this->setHitPoint(_defaultHitPoint);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this->getName() << " parameterized constructor" << std::endl;
	this->setAttackDamage(_defaultAttackDamage);
	this->setEnergyPoint(_defaultEnergyPoint);
	this->setHitPoint(_defaultHitPoint);
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap copy assignment " << this->getName() << " operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << " destructor" << std::endl;
}

void ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoint() == 0)
	{
		std::cout << WHITE << this->getName() << " has no energy left to attack... " RESET << std::endl;
		return ;
	}
	if (this->getHitPoint() == 0)
	{
		std::cout << WHITE << this->getName() << " dead..." RESET << std::endl;
		return ;
	}
	std::cout << RED << "ScavTrap " << this->getName() << " attacks " << target << " causing "
	<< this->getAttackDamage() << " points of damage!" RESET << std::endl;
	this->setEnergyPoint((this->getEnergyPoint()) - 1);
}

void ScavTrap::showStatistics( void )
{
	const int width = 50;
	std::cout << std::endl;
	std::cout << std::string(width, '=') << std::endl;
	std::cout << "| " << std::setw(width - 4) << std::left << ("ScavTrap " + this->getName() + " statistics:") << " |\n";
	std::cout << std::string(width, '-') << std::endl;
	std::cout << "| " << std::setw(width - 4) << std::left << ("Hit points:      " + std::to_string(this->getHitPoint())) << " |\n";
	std::cout << "| " << std::setw(width - 4) << std::left << ("Energy points:   " + std::to_string(this->getEnergyPoint())) << " |\n";
	std::cout << "| " << std::setw(width - 4) << std::left << ("Attack damage:   " + std::to_string(this->getAttackDamage())) << " |\n";
	std::cout << std::string(width, '=') << std::endl << std::endl;
}

unsigned int ScavTrap::getDefaultHitPoint() const
{
	return (this->_defaultHitPoint);
}

unsigned int ScavTrap::getDefaultEnergyPoint() const
{
	return (this->_defaultEnergyPoint);
}

unsigned int ScavTrap::getDefaultAttackDamage() const
{
	return (this->_defaultAttackDamage);
}
