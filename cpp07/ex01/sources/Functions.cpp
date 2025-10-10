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

#endif /* FUNCTIONS_HPP */
