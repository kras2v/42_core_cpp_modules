#include "testArrayType.tpp"
#include <iostream>
#include <string>
#include "Randomizer.hpp"
#include "Array.hpp"
#include "Point.hpp"

// Console colors
#define GREEN "\033[32m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

template <typename T>
bool testArrayType(const std::string& typeName, T generator())
{
	std::cout << CYAN << "=== Testing Array<" << typeName << "> ===" << RESET << std::endl;

	Array<T> customArr(SIZE);
	T* mirror = new T[SIZE];

	// Fill both arrays with same values
	for (int i = 0; i < SIZE; ++i)
	{
		T value = generator();
		customArr[i] = value;
		mirror[i] = value;
	}

	// Compare values
	bool allMatch = true;
	for (int i = 0; i < SIZE; ++i)
	{
		if (!(customArr[i] == mirror[i]))
		{
			std::cerr << RED << "Mismatch at index " << i << "!" << RESET << std::endl;
			allMatch = false;
		}
	}

	if (allMatch)
		std::cout << GREEN << "Initial assignment: All values match!" << RESET << std::endl;

	// Display values
	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << "customArr[" << i << "] = " << customArr[i] 
				<< " | mirror[" << i << "] = " << mirror[i] << std::endl;
	}

	// Test copy constructor and assignment operator
	std::cout << CYAN << "\n--- Testing copy constructor and assignment ---" << RESET << std::endl;
	Array<T> copy = customArr;
	Array<T> assigned;
	assigned = customArr;

	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << "copy[" << i << "] = " << copy[i] 
			<< " | assigned[" << i << "] = " << assigned[i] << std::endl;
	}

	// Mutate one copy
	std::cout << CYAN << "\n--- Modifying copy ---" << RESET << std::endl;
	for (int i = 0; i < SIZE; ++i)
		copy[i] = generator();

	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << "copy[" << i << "] = " << copy[i]
			<< " | original[" << i << "] = " << customArr[i] << std::endl;
	}

	// Bounds checking
	std::cout << CYAN << "\n--- Bounds checking ---" << RESET << std::endl;
	try
	{
		customArr[-1] = generator();
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Exception on negative index: " << e.what() << RESET << std::endl;
	}

	try
	{
		customArr[SIZE] = generator();
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Exception on out-of-bounds index: " << e.what() << RESET << std::endl;
	}

	delete[] mirror;
	std::cout << GREEN << "Test for Array<" << typeName << "> completed.\n" << RESET << std::endl;
	return !allMatch;
}

int main()
{
	bool failed = false;

	failed |= testArrayType<int>("int", Randomizer::randomInt);
	failed |= testArrayType<std::string>("std::string", Randomizer::randomString);
	failed |= testArrayType<Point>("Point", Randomizer::randomPoint);

	if (failed)
		std::cerr << RED << "Some tests failed!" << RESET << std::endl;
	else
		std::cout << GREEN << "All tests passed!" << RESET << std::endl;

	return failed ? 1 : 0;
}
