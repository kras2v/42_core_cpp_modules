#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

# include <iostream>
# include "Person.hpp"

void multiplyByTwo(int &arg)
{
	arg *= 2;
}

void inreaseSalary(Person &p)
{
	p.setSalary(p.getSalary() * 2);
}

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
