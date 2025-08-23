#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap bob("Bob");
	FragTrap mike("Mike");
	ClapTrap tom("Tom");

	bob.showStatistics();
	mike.showStatistics();
	tom.showStatistics();

	// Initial status
	std::cout << "\n--- Initial Attacks ---\n";
	bob.attack("Tom");
	tom.takeDamage(bob.getAttackDamage());

	mike.attack("Bob");
	bob.takeDamage(mike.getAttackDamage());

	tom.attack("Mike");
	mike.takeDamage(tom.getAttackDamage());

	// Special abilities
	std::cout << "\n--- Special Abilities ---\n";
	bob.guardGate();
	mike.highFivesGuys();

	// Chain attacks
	std::cout << "\n--- Chain Attacks ---\n";
	for (int i = 0; i < 3; ++i) {
		bob.attack("Mike");
		mike.takeDamage(bob.getAttackDamage());
	}

	for (int i = 0; i < 2; ++i) {
		mike.attack("Bob");
		bob.takeDamage(mike.getAttackDamage());
	}

	// Test energy depletion
	std::cout << "\n--- Energy Depletion ---\n";
	for (int i = 0; i < 12 && mike.getHitPoint() > 0 && bob.getHitPoint() > 0; ++i) {
		bob.attack("Mike");
		mike.takeDamage(bob.getAttackDamage());
	}

	// Test self-repair
	std::cout << "\n--- Self-Repair ---\n";
	bob.beRepaired(10);
	mike.beRepaired(5);
	tom.beRepaired(3);

	// Final attacks
	std::cout << "\n--- Final Attacks ---\n";
	bob.attack("Tom");
	tom.takeDamage(bob.getAttackDamage());

	mike.attack("Tom");
	tom.takeDamage(mike.getAttackDamage());

	return 0;
}