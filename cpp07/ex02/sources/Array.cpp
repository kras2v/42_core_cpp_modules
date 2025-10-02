#include "Array.hpp"

template <class T>
Array<T>::Array()
{
	this->_elements = new T[0];
}

template <class T>
Array<T>::~Array()
{
	this->_elements = new T[0];
}