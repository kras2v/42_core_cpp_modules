#include "HumanA.hpp"

HumanA::HumanA( std::string t_name, Weapon t_weapon )
	: _name(t_name), _weapon(t_weapon)
{
	#ifdef DEBUG
		std::cout << "HumanA constructor" << std::endl;
	#endif
}

HumanA::~HumanA()
{
	#ifdef DEBUG
		std::cout << "HumanA destructor" << std::endl;
	#endif
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType();
}