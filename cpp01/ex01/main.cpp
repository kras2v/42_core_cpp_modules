#include "Zombie.hpp"
#define ZOMBIE_COUNT 10

Zombie* zombieHorde( int N, std::string name );

int main( void )
{
	Zombie* zombiiiiez = zombieHorde(ZOMBIE_COUNT, "bob");
	for (size_t i = 0; i < ZOMBIE_COUNT; i++)
	{
		zombiiiiez[i].announce();
	}
	delete [] zombiiiiez;
	return (0);
}