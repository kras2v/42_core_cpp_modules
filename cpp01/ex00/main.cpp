#include "Zombie.hpp"

void randomChump( std::string t_name );
Zombie *newZombie( my_string t_name );

int main( void )
{
	Zombie bob("bob");
	bob.announce();
	my_cout << my_string('-', 45) << my_endl;
	Zombie *tom = newZombie("tom");
	tom->announce();
	my_cout << my_string('-', 45) << my_endl;
	randomChump("alex");
	my_cout << my_string('-', 45) << my_endl;
	delete(tom);
	return (0);
}