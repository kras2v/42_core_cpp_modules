#ifndef PERSON_HPP
# define PERSON_HPP

# include <string>
# include <iostream>

class Person
{
	private:
		const std::string _name;
		int _salary;

	public:
		Person();
		Person(const Person &other) = default;
		Person(std::string name, int salary);
		Person &operator=(const Person &other);
		~Person();

		const std::string &getName() const;
		int getSalary() const;

		void setSalary(int salary);
};

std::ostream &operator<<(std::ostream &ofs, const  Person &person);

#endif /* PERSON_HPP */