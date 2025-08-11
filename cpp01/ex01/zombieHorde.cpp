#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
	Zombie* zombiiiiiez = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombiiiiiez[i]._name = name;
	}
	return (zombiiiiiez);
}