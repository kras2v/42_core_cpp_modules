#include "iter.tpp"
#include "Functions.hpp"
#include "Person.hpp"

int main()
{
	{
		const int ints[5] = { 1, 2, 3, 4, 5};
		iter(ints, 5, printInFormat);
		std::cout << std::endl;

		// iter(ints, 5, multiplyByTwo);
	}
	std::cout << std::endl;
	{
		int ints[5] = { 1, 2, 3, 4, 5};
		iter(ints, 5, printInFormat);
		std::cout << std::endl;

		iter(ints, 5, multiplyByTwo);

		iter(ints, 5, printInFormat);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		const bool bools[5] = { true, false, true, true, true};
		iter(bools, 5, printInFormat);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		Person people[3] =
		{
			Person("bob1", 1000),
			Person("bob2", 2000),
			Person("bob3", 3000)
		};

		iter(people, 3, printInFormat);
		std::cout << std::endl;

		iter(people, 3, inreaseSalary);

		iter(people, 3, printInFormat);
		std::cout << std::endl;
	}

	return 0;
}