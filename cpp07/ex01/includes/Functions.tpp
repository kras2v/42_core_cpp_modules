#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

# include "Person.hpp"

void multiplyByTwo(int &arg);

void inreaseSalary(Person &p);

template <typename T>
void printInFormat(const T &arg)
{
	std::cout << "\"" << arg << "\"" << "\t";
}

template <>
void printInFormat<bool>(const bool &arg)
{
	std::cout << "\"" << std::boolalpha << arg << "\"" << "\t";
}

#endif /* FUNCTIONS_HPP */