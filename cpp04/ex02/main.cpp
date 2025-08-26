#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "AWrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define ANIMAL_COUNT 20

int main() {
	const AAnimal *animals[ANIMAL_COUNT];

	std::cout << "--- Initialize array of animals ---" << std::endl;
	for (size_t i = 0; i < ANIMAL_COUNT; i++)
		animals[i] = i < ANIMAL_COUNT / 2 ? (AAnimal*)new Dog() : (AAnimal*)new Cat();

	for (size_t i = 0; i < ANIMAL_COUNT; i++)
	{
		std::cout << animals[i]->getType() << "\t";
		animals[i]->makeSound();
	}

	//function returning abstract class "AAnimal" is not allowed:C/C++(323)
	/* const AAnimal animal(); */

	std::cout << "--- Delete array of animals ---" << std::endl;
	for (const AAnimal* &animal : animals)
		delete animal;
	return 0;
}
