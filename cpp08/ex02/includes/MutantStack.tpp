#include "MutantStack.hpp"
#include <iostream>

template <typename _Tp>
MutantStack<_Tp>::MutantStack() : std::stack<_Tp>()
{
	#ifdef DEBUG
		std::cout << "MutantStack: default constructor" << std::endl;
	#endif
}

template <typename _Tp>
MutantStack<_Tp>::MutantStack(const MutantStack<_Tp>& other) : std::stack<_Tp>(other)
{
	#ifdef DEBUG
		std::cout << "MutantStack: copy constructor" << std::endl;
	#endif
}

template <typename _Tp>
MutantStack<_Tp>& MutantStack<_Tp>::operator=(const MutantStack<_Tp>& other)
{
	if (this != &other)
	{
		std::stack<_Tp>::operator=(other);
	}
	#ifdef DEBUG
		std::cout << "MutantStack: copy assignment operator" << std::endl;
	#endif
	return *this;
}

template <typename _Tp>
MutantStack<_Tp>::~MutantStack()
{
	#ifdef DEBUG
		std::cout << "MutantStack: destructor" << std::endl;
	#endif
}

template <typename _Tp>
typename MutantStack<_Tp>::iterator MutantStack<_Tp>::begin()
{
	#ifdef DEBUG
		std::cout << "MutantStack: begin()" << std::endl;
	#endif
	return this->c.begin();
}

template <typename _Tp>
typename MutantStack<_Tp>::iterator MutantStack<_Tp>::end()
{
	#ifdef DEBUG
		std::cout << "MutantStack: end()" << std::endl;
	#endif
	return this->c.end();
}