#include "Zombie.hpp"
#define N 10

int main( void )
{
	Zombie bob = Zombie("leader");
	Zombie* zombiiiiez = bob.zombieHorde(N, "bob");
	for (size_t i = 0; i < N; i++)
	{
		zombiiiiez[i].announce();
	}
	delete [] zombiiiiez;
	return (0);
}