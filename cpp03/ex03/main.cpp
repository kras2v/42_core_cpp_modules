#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap bob("bob");
	bob.showStatistics();
	bob.whoAmI();
	std::cout << std::endl;

	DiamondTrap tom(bob);
	tom.showStatistics();

	tom.attack("bob");
	bob.takeDamage(bob.getAttackDamage());
	return 0;
}