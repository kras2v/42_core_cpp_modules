#ifndef ARRAY_HPP
# define ARRAY_HPP

# include "Array.tpp"

template <typename T>
Array<T>::Array() : _size(0)
{
	this->_elements = nullptr;
	#ifdef DEBUG
		std::cout << "Array default constructor" << std::endl;
	#endif
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	this->_elements = new T[n];
	initByDefault();
	#ifdef DEBUG
		std::cout << "Array parametrized constructor, size: " << n << std::endl;
	#endif
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->_elements;
	#ifdef DEBUG
		std::cout << "Array destructor" << std::endl;
	#endif
}

template <typename T>
Array<T>::Array(const Array<T> &other) : _size(other.size())
{
	this->_elements = nullptr;
	*this = other;
	#ifdef DEBUG
		std::cout << "Array copy constructor" << std::endl;
	#endif
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &other)
{
	#ifdef DEBUG
		std::cout << "Array assignment operator" << std::endl;
	#endif
	if (this != &other)
	{
		if (this->_elements)
		{
			delete [] this->_elements;
		}
		this->_size = other.size();
		this->_elements = new T[other.size()];
		for (size_t i = 0; i < this->_size; i++)
		{
			this->_elements[i] = other[i];
		}
	}
	return *this;
}

template <typename T>
template <typename U>
Array<T>::Array(const Array<U> &other) : _size(other.size())
{
	this->_elements = nullptr;
	*this = other;
	#ifdef DEBUG
		std::cout << "Array copy constructor" << std::endl;
	#endif
}

template <typename T>
template <typename U>
Array<T>& Array<T>::operator=(const Array<U> &other)
{
	#ifdef DEBUG
		std::cout << "Array assignment operator" << std::endl;
	#endif
	if (this->_elements)
	{
		delete [] this->_elements;
	}
	this->_size = other.size();
	this->_elements = new T[other.size()];
	for (size_t i = 0; i < this->_size; i++)
	{
		this->_elements[i] = static_cast<T>(other[i]);
	}
	return *this;
}

template <typename T>
T & Array<T>::operator[](unsigned int index) const
{
	if (index < this->_size)
	{
		return this->_elements[index];
	}
	throw OutOfBoundsException();
}

template <typename T>
const char * Array<T>::OutOfBoundsException::what() const noexcept
{
	return "Index out of bounds!";
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}

template <typename T>
void Array<T>::initByDefault()
{
	for (size_t i = 0; i < this->_size; i++)
	{
		this->_elements[i] = T();
	}
}

#endif /* ARRAY_HPP */