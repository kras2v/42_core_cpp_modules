#include "ClapTrap.hpp"

const unsigned int ClapTrap::_defaultHitPoint = 10;
const unsigned int ClapTrap::_defaultEnergyPoint = 10;
const unsigned int ClapTrap::_defaultAttackDamage = 0;

ClapTrap::ClapTrap()
	: _name("default"),
	_hitPoint(_defaultHitPoint),
	_energyPoint(_defaultEnergyPoint),
	_attackDamage(_defaultAttackDamage)
{
	std::cout << "ClapTrap " << this->getName() << " default constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap " << this->getName() << " copy constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
	: _name(name),
	_hitPoint(_defaultHitPoint),
	_energyPoint(_defaultEnergyPoint),
	_attackDamage(_defaultAttackDamage)
{
	std::cout << "ClapTrap " << this->getName() << " custom constructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoint = other._hitPoint;
		this->_energyPoint = other._energyPoint;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap copy assignment " << this->_name << " operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->getName() << " destructor" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoint == 0)
	{
		std::cout << WHITE << this->getName() << " has no energy left to attack... " RESET << std::endl;
		return ;
	}
	if (this->_hitPoint == 0)
	{
		std::cout << WHITE << this->getName() << " dead..." RESET << std::endl;
		return ;
	}
	std::cout << RED << "ClapTrap " << this->getName() << " attacks " << target << " causing "
	<< this->_attackDamage << " points of damage!" RESET << std::endl;
	this->_energyPoint--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint == 0)
	{
		std::cout << WHITE << this->getName() << " dead... " RESET << std::endl;
		return ;
	}
	std::cout << BLUE << this->getName() << " is being attacked and losing "
	<< amount << " hit points" RESET << std::endl;
	if (this->_hitPoint < amount)
		this->_hitPoint = 0;
	else
		this->_hitPoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoint == 0)
	{
		std::cout << WHITE << this->getName() << " has no energy left to be rapaired... " RESET << std::endl;
		return ;
	}
	if (this->_hitPoint == 0)
	{
		std::cout << WHITE << this->getName() << " dead..." RESET << std::endl;
		return ;
	}
	std::cout << BLUE << this->getName() << " repairs itself, it regains "
	<< amount << " hit points" RESET << std::endl;
	this->_hitPoint += amount;
	this->_energyPoint--;
}

void ClapTrap::showStatistics()
{
	const int width = 50;
	std::cout << std::endl;
	std::cout << std::string(width, '=') << std::endl;
	std::cout << "| " << std::setw(width - 4) << std::left << ("ClapTrap " + this->getName() + " statistics:") << " |\n";
	std::cout << std::string(width, '-') << std::endl;
	std::cout << "| " << std::setw(width - 4) << std::left << ("Hit points:      " + std::to_string(this->_hitPoint)) << " |\n";
	std::cout << "| " << std::setw(width - 4) << std::left << ("Energy points:   " + std::to_string(this->_energyPoint)) << " |\n";
	std::cout << "| " << std::setw(width - 4) << std::left << ("Attack damage:   " + std::to_string(this->_attackDamage)) << " |\n";
	std::cout << std::string(width, '=') << std::endl << std::endl;
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}

unsigned int ClapTrap::getHitPoint() const
{
	return (this->_hitPoint);
}

unsigned int ClapTrap::getEnergyPoint() const
{
	return (this->_energyPoint);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}

void ClapTrap::setName( const std::string name )
{
	this->_name = name;
}

void ClapTrap::setHitPoint( unsigned int hitP )
{
	this->_hitPoint = hitP;
}

void ClapTrap::setEnergyPoint( unsigned int energyP )
{
	this->_energyPoint = energyP;
}

void ClapTrap::setAttackDamage( unsigned int attackDamage )
{
	this->_attackDamage = attackDamage;
}

unsigned int ClapTrap::getDefaultHitPoint() const
{
	return (this->_defaultHitPoint);
}

unsigned int ClapTrap::getDefaultEnergyPoint() const
{
	return (this->_defaultEnergyPoint);
}

unsigned int ClapTrap::getDefaultAttackDamage() const
{
	return (this->_defaultAttackDamage);
}
