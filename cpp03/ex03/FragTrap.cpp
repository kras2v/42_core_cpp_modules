#include "FragTrap.hpp"

const unsigned int FragTrap::_defaultHitPoint = 100;
const unsigned int FragTrap::_defaultEnergyPoint = 100;
const unsigned int FragTrap::_defaultAttackDamage = 30;

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap " << this->getName() << " default constructor" << std::endl;
	this->setAttackDamage(this->_defaultAttackDamage);
	this->setEnergyPoint(this->_defaultEnergyPoint);
	this->setHitPoint(this->_defaultHitPoint);
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap " << this->getName() << " copy constructor" << std::endl;
	this->setAttackDamage(this->_defaultAttackDamage);
	this->setEnergyPoint(this->_defaultEnergyPoint);
	this->setHitPoint(this->_defaultHitPoint);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << this->getName() << " custom constructor" << std::endl;
	this->setAttackDamage(this->_defaultAttackDamage);
	this->setEnergyPoint(this->_defaultEnergyPoint);
	this->setHitPoint(this->_defaultHitPoint);
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "Copy assignment " << this->getName() << " operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->getName() << " destructor" << std::endl;
}

void FragTrap::attack(const std::string& target)
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
	std::cout << RED << "FragTrap " << this->getName() << " attacks " << target << " causing "
	<< this->getAttackDamage() << " points of damage!" RESET << std::endl;
	this->setEnergyPoint((this->getEnergyPoint()) - 1);
}

void FragTrap::highFivesGuys( void )
{
	std:: cout
	<< "                     _.-._" << std::endl
	<< "   Yo               | | | |_" << std::endl
	<< "    High            | | | | |" << std::endl
	<< "      Five          | | | | |" << std::endl
	<< "        Bro!      _ |  '-._ |" << std::endl
	<< "                  \\`\\`-.'-._;" << std::endl
	<< "                   \\    '   |" << std::endl
	<< "                    \\  .`  /" << std::endl
	<< "                     |    |" << std::endl;
}

void FragTrap::showStatistics( void )
{
	const int width = 50;
	std::cout << std::endl;
	std::cout << std::string(width, '=') << std::endl;
	std::cout << "| " << std::setw(width - 4) << std::left << ("FragTrap " + this->getName() + " statistics:") << " |\n";
	std::cout << std::string(width, '-') << std::endl;
	std::cout << "| " << std::setw(width - 4) << std::left << ("Hit points:      " + std::to_string(this->getHitPoint())) << " |\n";
	std::cout << "| " << std::setw(width - 4) << std::left << ("Energy points:   " + std::to_string(this->getEnergyPoint())) << " |\n";
	std::cout << "| " << std::setw(width - 4) << std::left << ("Attack damage:   " + std::to_string(this->getAttackDamage())) << " |\n";
	std::cout << std::string(width, '=') << std::endl << std::endl;
}

unsigned int FragTrap::getDefaultHitPoint() const
{
	return (this->_defaultHitPoint);
}

unsigned int FragTrap::getDefaultEnergyPoint() const
{
	return (this->_defaultEnergyPoint);
}

unsigned int FragTrap::getDefaultAttackDamage() const
{
	return (this->_defaultAttackDamage);
}
