#include "Brain.hpp"

const unsigned int Brain::_ideas_count = 100;

Brain::Brain ( void )
{
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain ( const Brain &other )
{
	std::cout << "Brain copy constructor" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment operator" << std::endl;
	if (this != &other)
	{
		for (size_t i = 0; i < 100; i++)
		{
			this->_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

