#include "Zombie.hpp"

int main( void )
{
	Zombie bob("bob");
	bob.announce();
	my_cout << my_string('-', 45) << my_endl;
	Zombie *tom = bob.newZombie("tom");
	tom->announce();
	my_cout << my_string('-', 45) << my_endl;
	tom->randomChump("alex");
	my_cout << my_string('-', 45) << my_endl;
	delete(tom);
	return (0);
}