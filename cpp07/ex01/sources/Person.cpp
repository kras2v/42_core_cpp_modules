#include "Person.hpp"

Person::Person() : _name("Bob"), _salary(20000)
{
	
}

Person::Person(std::string name, int salary) : _name(name), _salary(salary)
{
	
}

Person::~Person()
{
}

Person &Person::operator=(const Person &other)
{
	(void)other;
	return *this;
}

const std::string &Person::getName() const
{
	return this->_name;
}

int Person::getSalary() const
{
	return this->_salary;
}

void Person::setSalary(int salary)
{
	this->_salary = salary;
}

std::ostream &operator<<(std::ostream &ofs, const Person &person)
{
	ofs << "Name: " << person.getName() << "|" << "Salary: " << person.getSalary();
	return ofs;
}
