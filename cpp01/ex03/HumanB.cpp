#include "HumanB.hpp"

HumanB::HumanB( std::string t_name, Weapon t_weapon )
	: _name(t_name), _weapon(&t_weapon)
{
	#ifdef DEBUG
		std::cout << "HumanB constructor" << std::endl;
	#endif
}

HumanB::HumanB( std::string t_name )
	: _name(t_name), _weapon(nullptr)
{
	#ifdef DEBUG
		std::cout << "HumanB constructor" << std::endl;
	#endif
	delete _weapon;
}

HumanB::~HumanB()
{
	#ifdef DEBUG
		std::cout << "HumanB destructor" << std::endl;
	#endif
}

void HumanB::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType();
}

void HumanB::setWeapon(Weapon &t_weapon)
{
	this->_weapon = &t_weapon;
}
