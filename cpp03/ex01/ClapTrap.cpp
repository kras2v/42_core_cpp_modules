#include "ClapTrap.hpp"

# define RED			"\e[0;31m"
# define BLUE			"\e[0;34m"
# define WHITE			"\e[0;37m"
# define RESET			"\e[0m"
# define HIT_POINTS		100
# define ENERGY_POINTS	50
# define ATACK_DAMAGE	20

ClapTrap::ClapTrap()
	: _name("noname"),
	_hitPoint(HIT_POINTS),
	_energyPoint(ENERGY_POINTS),
	_attackDamage(ATACK_DAMAGE)
{
	std::cout << "ClapTrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoint = other._hitPoint;
		this->_energyPoint = other._energyPoint;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
	: _name(name),
	_hitPoint(HIT_POINTS),
	_energyPoint(ENERGY_POINTS),
	_attackDamage(ATACK_DAMAGE)
{
	std::cout << "ClapTrap custom constructor" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoint == 0)
	{
		std::cout << WHITE << this->_name << " has no energy left to attack... " RESET << std::endl;
		return ;
	}
	if (this->_hitPoint == 0)
	{
		std::cout << WHITE << this->_name << " dead..." RESET << std::endl;
		return ;
	}
	std::cout << RED << this->_name << " attacks " << target << " causing "
	<< this->_attackDamage << " points of damage!" RESET << std::endl;
	this->_energyPoint--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint == 0)
	{
		std::cout << WHITE << this->_name << " dead... " RESET << std::endl;
		return ;
	}
	std::cout << BLUE << this->_name << " is being attacked and losing "
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
		std::cout << WHITE << this->_name << " has no energy left to be rapaired... " RESET << std::endl;
		return ;
	}
	if (this->_hitPoint == 0)
	{
		std::cout << WHITE << this->_name << " dead..." RESET << std::endl;
		return ;
	}
	std::cout << BLUE << this->_name << " repairs itself, it regains "
	<< amount << " hit points" RESET << std::endl;
	this->_hitPoint += amount;
	this->_energyPoint--;
}

void ClapTrap::showStatistics()
{
	const int width = 32;
	std::cout << std::endl;
	std::cout << std::string(width, '=') << std::endl;
	std::cout << "| " << std::setw(width - 4) << std::left << (this->_name + " statistics:") << " |\n";
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
