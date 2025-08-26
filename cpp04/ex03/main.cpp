#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character alice("Alice");

	// Equip Materias
	alice.equip(src->createMateria("ice"));
	alice.equip(src->createMateria("cure"));
	alice.equip(src->createMateria("ice"));

	std::cout << "\n--- Alice inventory after equipping ---\n";
	alice.showInventory();

	// Unequip invalid and valid slots
	alice.unequip(10); // invalid
	alice.unequip(1);  // valid
	std::cout << "\n--- Alice inventory after unequipping slots 1 and 10 ---\n";
	alice.showInventory();

	// Copy constructor test
	Character aliceCopy(alice);
	std::cout << "\n--- aliceCopy inventory after copy constructor ---\n";
	aliceCopy.showInventory();

	// Copy assignment test
	Character bob("Bob");
	bob = alice;
	std::cout << "\n--- bob inventory after assignment from Alice ---\n";
	bob.showInventory();

	// Equip more Materias to test deep copy
	aliceCopy.equip(src->createMateria("cure"));
	bob.equip(src->createMateria("ice"));

	std::cout << "\n--- Inventories after additional equips ---\n";
	std::cout << "aliceCopy:\n"; aliceCopy.showInventory();
	std::cout << "bob:\n"; bob.showInventory();

	// Use Materias including empty slots
	std::cout << "\n--- Using Materias ---\n";
	for (size_t i = 0; i < 4; i++) {
		alice.use(i, alice);
	}
	std::cout << "********************************************" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		aliceCopy.use(i, aliceCopy);
	}
	std::cout << "********************************************" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		bob.use(i, bob);
	}
	delete src;

	std::cout << "\n--- Test finished ---\n";
	return 0;
}
