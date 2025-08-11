#include "Zombie.hpp"

void Zombie::randomChump( std::string t_name )
{
	Zombie new_zombie(t_name);
	new_zombie.announce();
}
