#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
	// ======== Setup source ========
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// ======== Create Characters ========
	Character* alice = new Character("Alice");

	// ======== Equip Alice with Materias ========
	AMateria* ice = src->createMateria("ice");
	AMateria* cure = src->createMateria("cure");
	AMateria* ice2 = src->createMateria("ice");

	alice->equip(ice);
	alice->equip(cure);
	alice->equip(ice2);

	std::cout << "\n--- Alice's inventory after equipping 3 Materias ---\n";
	alice->showInventory();

	// ======== Unequip some Materias ========
	alice->unequip(1);  // unequip Cure
	alice->unequip(0);  // unequip Ice
	std::cout << "\n--- Alice's inventory after unequipping slots 0 and 1 ---\n";
	alice->showInventory();

	// ======== Copy constructor check ========
	Character* aliceCopy = new Character(*alice);
	std::cout << "\n--- aliceCopy inventory after copy constructor ---\n";
	aliceCopy->showInventory();

	// Equip a new Materia in aliceCopy
	AMateria* cure2 = src->createMateria("cure");
	aliceCopy->equip(cure2);

	std::cout << "\n--- aliceCopy inventory after equipping new Cure ---\n";
	aliceCopy->showInventory();

	std::cout << "\n--- Original Alice inventory should remain unchanged ---\n";
	alice->showInventory();

	// ======== Copy assignment operator check ========
	Character bobCopy("BobCopy");
	bobCopy = *alice;  // assignment
	std::cout << "\n--- bobCopy inventory after assignment from Alice ---\n";
	bobCopy.showInventory();

	// Equip a Materia in bobCopy to ensure deep copy
	AMateria* ice3 = src->createMateria("ice");
	bobCopy.equip(ice3);
	std::cout << "\n--- bobCopy inventory after equipping new Ice ---\n";
	bobCopy.showInventory();

	std::cout << "\n--- Original Alice inventory should still be unchanged ---\n";
	alice->showInventory();

	// ======== Use Materias ========
	std::cout << "\n--- Using Alice's Materias ---\n";
	for (size_t i = 0; i < 3; i++)
		alice->use(i, *alice);

	std::cout << "\n--- Using aliceCopy's Materias ---\n";
	for (size_t i = 0; i < 4; i++)
		aliceCopy->use(i, *aliceCopy);

	std::cout << "\n--- Using bobCopy's Materias ---\n";
	for (size_t i = 0; i < 4; i++)
		bobCopy.use(i, bobCopy);

	// ======== Clean up ========
	delete alice;
	delete aliceCopy;
	delete src;

	std::cout << "\n--- Test finished successfully ---\n";
	return 0;
}
