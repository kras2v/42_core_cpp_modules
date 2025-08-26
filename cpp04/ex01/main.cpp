#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define ANIMAL_COUNT 20

int main() {
	const Animal *animals[ANIMAL_COUNT];

	std::cout << "--- Initialize array of animals ---" << std::endl;
	for (size_t i = 0; i < ANIMAL_COUNT; i++)
		animals[i] = i < ANIMAL_COUNT / 2 ? (Animal*)new Dog() : (Animal*)new Cat();

	for (size_t i = 0; i < ANIMAL_COUNT; i++)
	{
		std::cout << animals[i]->getType() << "\t";
		animals[i]->makeSound();
	}

	Cat cat;
	{
		std::cout << "--- Deep copy check with copy constructor ---" << std::endl;
		Cat catDeepCopy(cat);
		std::cout << "Original cat brain address: " << &cat << std::endl;
		std::cout << "Deep copy cat brain address: " << &catDeepCopy << std::endl;

		catDeepCopy.makeSound();
		catDeepCopy.makeSound();
		catDeepCopy.makeSound();
	}

	{
		std::cout << "--- Deep copy check with assignment operator ---" << std::endl;
		Cat catDeepCopy;
		catDeepCopy = cat;
		std::cout << "Original cat brain address: " << &cat << std::endl;
		std::cout << "Deep copy cat brain address: " << &catDeepCopy << std::endl;

		catDeepCopy.makeSound();
		catDeepCopy.makeSound();
		catDeepCopy.makeSound();
	}

	std::cout << "--- Delete array of animals ---" << std::endl;
	for (const Animal* &animal : animals)
		delete animal;
	return 0;
}
