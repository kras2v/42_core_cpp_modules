#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void testAnimalBasics() {
	std::cout << "\n--- Animal Basics ---\n";
	Animal a;
	std::cout << "Type: " << a.getType() << std::endl;
	a.makeSound();
}

void testCatDog() {
	std::cout << "\n--- Cat and Dog ---\n";
	Cat c;
	Dog d;
	std::cout << "Cat type: " << c.getType() << std::endl;
	std::cout << "Dog type: " << d.getType() << std::endl;
	c.makeSound();
	d.makeSound();
}

void testPolymorphism() {
	std::cout << "\n--- Polymorphism ---\n";
	const Animal* a1 = new Cat();
	const Animal* a2 = new Dog();
	std::cout << "a1 type: " << a1->getType() << std::endl;
	std::cout << "a2 type: " << a2->getType() << std::endl;
	a1->makeSound();
	a2->makeSound();
	delete a1;
	delete a2;
}

void testWrongAnimal() {
	std::cout << "\n--- WrongAnimal Polymorphism ---\n";
	const AWrongAnimal* wa = new WrongCat();
	std::cout << "wa type: " << wa->getType() << std::endl;
	wa->makeSound();
	delete wa;
}

void testCopyAndAssign() {
	std::cout << "\n--- Copy and Assignment ---\n";
	{
		Cat c1;
		std::cout << "c1 type: " << c1.getType() << std::endl;

		Animal c2;
		c2 = c1;
		std::cout << "c2 type: " << c2.getType() << std::endl;

		Cat c3(c1);
		std::cout << "c3 type: " << c3.getType() << std::endl;
	}
	{
		Dog d1;
		std::cout << "d1 type: " << d1.getType() << std::endl;

		Animal d2;
		d2 = d1;
		std::cout << "d2 type: " << d2.getType() << std::endl;

		Dog d3 (d1);
		std::cout << "d3 type: " << d3.getType() << std::endl;

	}
}

int main() {
	testAnimalBasics();
	testCatDog();
	testPolymorphism();
	testWrongAnimal();
	testCopyAndAssign();
	return 0;
}
