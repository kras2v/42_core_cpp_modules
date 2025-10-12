#include "Span.hpp"

template <typename iter>
Span::Span(iter first, iter last)
{
	#ifdef DEBUG
		std::cout << "Span parametrized constructor" << std::endl;
	#endif
	this->_N = std::distance(first, last);
	while (first != last)
	{
		this->_elements.push_back(*first);
		first++;
	}
}

template <typename iter>
void Span::addNumber(iter begin, iter end)
{
	if (this->_elements.size() + 1 > this->_N)
		throw Span::MaxElementsCountException();

	while (begin != end)
	{
		this->_elements.push_back(*begin);
		begin++;
	}
	this->_isUpdated = true;
}