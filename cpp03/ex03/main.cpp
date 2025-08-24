#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap bob("bob");
	bob.showStatistics();
	bob.whoAmI();
	bob.guardGate();
	bob.highFivesGuys();

	std::cout << std::string(50, '-') << std::endl << std::endl;

	ScavTrap tom = bob;
	tom.showStatistics();
	tom.guardGate();

	std::cout << std::string(50, '-') << std::endl << std::endl;

	FragTrap alex(bob);
	alex.showStatistics();
	alex.highFivesGuys();

	tom.attack("bob");
	bob.takeDamage(tom.getAttackDamage());
	tom.attack("alex");
	alex.takeDamage(tom.getAttackDamage());
	bob.showStatistics();
	tom.showStatistics();
	alex.showStatistics();
	return (0);
}
