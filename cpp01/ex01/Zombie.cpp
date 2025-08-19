#include "Zombie.hpp"

Zombie::Zombie()
{
	my_cout << "Zombie default constructor" << my_endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	my_cout << "Zombie with name " << this->_name << " destroyed" << my_endl;
}

void Zombie::announce( void )
{
	my_cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << my_endl;
}
