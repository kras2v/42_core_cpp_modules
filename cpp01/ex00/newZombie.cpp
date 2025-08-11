#include "Zombie.hpp"

Zombie* Zombie::newZombie( my_string t_name )
{
	Zombie *new_zombie = new Zombie(t_name);
	return (new_zombie);
}
