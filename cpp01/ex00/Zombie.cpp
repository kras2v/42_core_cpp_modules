#include "Zombie.hpp"

Zombie::Zombie()
{
	my_cout << "Zombie default constructor" << my_endl;
}

Zombie::Zombie(my_string t_name): _name(t_name)
{
	my_cout << "Zombie with name " << this->_name << " is born" << my_endl;
}

Zombie::~Zombie()
{
	my_cout << "Zombie with name " << this->_name << " died" << my_endl;
}

void Zombie::announce( void )
{
	my_cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << my_endl;
}
