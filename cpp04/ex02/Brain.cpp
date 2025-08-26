#include "Brain.hpp"

Brain::Brain ( void )
{
	#ifndef DEBUG
		std::cout << "Brain default constructor" << std::endl;
	#endif
}

Brain::Brain ( const Brain &other )
{
	*this = other;
	#ifndef DEBUG
		std::cout << "Brain copy constructor" << std::endl;
	#endif
}

Brain::~Brain()
{
	#ifndef DEBUG
		std::cout << "Brain destructor" << std::endl;
	#endif
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < 100; i++)
		{
			this->_ideas[i] = other._ideas[i];
		}
	}
	#ifndef DEBUG
		std::cout << "Brain copy assignment operator" << std::endl;
	#endif
	return (*this);
}

