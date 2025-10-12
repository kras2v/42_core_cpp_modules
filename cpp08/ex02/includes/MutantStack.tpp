#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
	#ifdef DEBUG
		std::cout << "CustomList default constructor" << std::endl;
	#endif
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	#ifdef DEBUG
		std::cout << "CustomList destructor" << std::endl;
	#endif
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other)
{
	#ifdef DEBUG
		std::cout << "CustomList copy constructor" << std::endl;
	#endif
	this->_elements = other.getList();
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack &other)
{
	#ifdef DEBUG
		std::cout << "CustomList assignment operator" << std::endl;
	#endif
	if (this != &other)
	{
		this->_elements = other.getList();
	}
	return *this;
}

template <typename T>
void MutantStack<T>::clear()
{
	this->_elements.empty();
}

template <typename T>
bool MutantStack<T>::empty() const
{
	return this->_elements.getSize() == 0;
}

template <typename T>
size_t		MutantStack<T>::size() const
{
	return this->_elements.size();
}

template <typename T>
T	MutantStack<T>::top() const
{
	return this->_elements.front();
}

template <typename T>
void MutantStack<T>::pop()
{
	this->_elements.pop_front();
}

template <typename T>
void MutantStack<T>::push(const T &element)
{
	this->_elements.push_front(element);
}

template <typename T>
const std::deque<T> &MutantStack<T>::getList() const
{
	return this->_elements;
}

template <typename T>
MutantStack<T>::iterator::iterator(T* node)
{
	this->pointer = node;
	#ifdef DEBUG
		std::cout << "iterator default constructor " << std::endl;
	#endif
}

template <typename T>
const T & MutantStack<T>::iterator::operator*() const
{
	return *this->pointer;
}

template <typename T>
bool MutantStack<T>::iterator::operator==(const MutantStack<T>::iterator &other) const
{
	return this->pointer == other.pointer;
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(const MutantStack<T>::iterator &other) const
{
	return this->pointer != other.pointer;
}

template <typename T>
T &MutantStack<T>::iterator::operator++()
{
	this->pointer++;
	return *this->pointer;
}

template <typename T>
T &MutantStack<T>::iterator::operator--()
{
	this->pointer--;
	return *this->pointer;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return MutantStack<T>::iterator(&this->_elements.front());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	MutantStack<T>::iterator end = MutantStack<T>::iterator(&this->_elements.back() + 1);
	return end;
}

template <typename T>
MutantStack<T>::iterator::iterator(const iterator &other)
{
	this->pointer = other.pointer;
	#ifdef DEBUG
		std::cout << "iterator copy constructor" << std::endl;
	#endif
}

template <typename T>
typename MutantStack<T>::iterator & MutantStack<T>::iterator::operator=(const iterator &other)
{
	#ifdef DEBUG
		std::cout << "iterator assignment operator" << std::endl;
	#endif
	if (this != &other)
	{
		this->pointer = other.pointer;
	}
	return *this;
}

template <typename T>
MutantStack<T>::iterator::~iterator()
{
	#ifdef DEBUG
		std::cout << "iterator destructor" << std::endl;
	#endif
}
