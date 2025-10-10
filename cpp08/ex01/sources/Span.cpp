#include "Span.hpp"

Span::Span() : _N(10000), _shortestSpan(INT32_MAX), _longestSpan(0)
{
	#ifdef DEBUG
		std::cout << "Span default constructor" << std::endl;
	#endif
}

Span::Span(const Span &other) : _N(other._N), _shortestSpan(other.shortestSpan()), _longestSpan(other.longestSpan())
{
	#ifdef DEBUG
		std::cout << "Span copy constructor" << std::endl;
	#endif
	this->_elements.clear();
	this->_elements = other._elements;
}

Span & Span::operator=(const Span &other)
{
	#ifdef DEBUG
		std::cout << "Span assignment operator" << std::endl;
	#endif
	if (this != &other)
	{
		this->_N = other._N;
		this->_elements.clear();
		this->_elements = other._elements;
	}
	return *this;
}

Span::~Span()
{
	#ifdef DEBUG
		std::cout << "Span destructor" << std::endl;
	#endif
	this->_elements.clear();
}

Span::Span(unsigned int N) : _N(N), _shortestSpan(INT32_MAX), _longestSpan(0)
{
	#ifdef DEBUG
		std::cout << "Span parametrized constructor" << std::endl;
	#endif
}

int Span::getSecondNumber() const
{
	int count = 0;
	for (int elem : this->_elements)
	{
		if (count == 1)
		{
			return elem;
		}
		count++;
	}
	return 0;
}

void Span::calculateShortestSpan()
{
	this->_elements.sort();

	std::list<int>::iterator current = this->_elements.begin();
	std::list<int>::iterator end = this->_elements.end();
	while (current != end)
	{
		std::list<int>::iterator next = current;
		next++;
		if (next != end && abs(*current - *next) <= this->_shortestSpan)
		{
			this->_shortestSpan = abs(*current - *next);
		}
		current++;
	}
}

void Span::addNumber(int numb)
{
	if (this->_elements.size() + 1 > this->_N)
		throw Span::MaxElementsCountException();

	this->_elements.push_back(numb);
	this->_isUpdated = true;
}

int Span::shortestSpan()
{
	if (this->_elements.size() < 2)
		throw Span::NotEnoughElementsException();

	if (this->_isUpdated)
		calculateShortestSpan();
	return this->_shortestSpan;
}

int Span::longestSpan()
{
	if (this->_elements.size() < 2)
		throw Span::NotEnoughElementsException();

	std::list<int>::iterator begin = this->_elements.begin();
	std::list<int>::iterator end = this->_elements.end();

	if (this->_isUpdated)
		this->_longestSpan = *std::max_element(begin, end)
		- *std::min_element(begin, end);
	return this->_longestSpan;
}

int Span::shortestSpan() const
{
	if (this->_elements.size() < 2)
		throw Span::NotEnoughElementsException();
	return this->_shortestSpan;
}

int Span::longestSpan() const
{
	if (this->_elements.size() < 2)
		throw Span::NotEnoughElementsException();
	return this->_longestSpan;
}

#ifdef DEBUG
	void Span::print()
	{
		for (int elem : this->_elements)
		{
			std::cout << elem << "\t";
		}
		std::cout << std::endl;
	}
#endif

unsigned int Span::getN() const
{
	return this->_N;
}

const char *Span::MaxElementsCountException::what() const noexcept
{
	return "Max elements amount reached!";
}

const char *Span::NotEnoughElementsException::what() const noexcept
{
	return "There is not enough elements in Span!";
}
