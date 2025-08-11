#include "Weapon.hpp"

Weapon::Weapon(std::string t_type)
{
	#ifdef DEBUG
		std::cout << "Weapon constructor" << std::endl;
	#endif
	this->_type = t_type;
}

Weapon::~Weapon()
{
	#ifdef DEBUG
		std::cout << "Weapon destructor" << std::endl;
	#endif
}

const std::string &Weapon::getType()
{
	return (this->_type);
}

void Weapon::setType(std::string t_type)
{
	this->_type = t_type;
}