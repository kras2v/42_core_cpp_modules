#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap bob("Bob");

	ClapTrap tom(bob);
	std::cout << "Name after copy constructor: " << tom.getName() << std::endl;
	tom.setName("Tom");

	bob.showStatistics();
	tom.showStatistics();

	std::cout << "\n--- Initial Attacks ---\n";
	bob.attack("Tom");
	tom.takeDamage(bob.getAttackDamage());

	tom.attack("Bob");
	bob.takeDamage(tom.getAttackDamage());

	std::cout << "\n--- Special Abilities ---\n";
	bob.guardGate();
	/* tom.guardGate(); */

	std::cout << "\n--- Chain Attacks ---\n";
	for (int i = 0; i < 3; ++i) {
		bob.attack("Tom");
		tom.takeDamage(bob.getAttackDamage());
	}

	for (int i = 0; i < 2; ++i) {
		tom.attack("Bob");
		bob.takeDamage(tom.getAttackDamage());
	}

	std::cout << "\n--- Energy Depletion ---\n";
	for (int i = 0; i < 12; ++i) {
		tom.attack("Bob");
	}

	std::cout << "\n--- Self-Repair ---\n";
	bob.beRepaired(10);
	tom.beRepaired(3);

	std::cout << "\n--- Final Attacks ---\n";
	bob.attack("Tom");
	tom.takeDamage(bob.getAttackDamage());

	return 0;
}