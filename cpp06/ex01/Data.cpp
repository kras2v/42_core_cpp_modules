#include "Data.hpp"

Data::Data(std::string name) : _name(name)
{
	#ifdef DEBUG
		std::cout << "Data constructor" << std::endl;
	#endif
}

Data::Data(const Data &other)
{
	#ifdef DEBUG
		std::cout << "Data copy constructor" << std::endl;
	#endif
}

Data &Data::operator=(const Data &other)
{
	#ifdef DEBUG
		std::cout << "Data assignment operator" << std::endl;
	#endif
	(void)other;
	return *this;
}

Data::~Data()
{
	#ifdef DEBUG
		std::cout << "Data destructor" << std::endl;
	#endif
}

const std::string &Data::getName()
{
	return this->_name;
}