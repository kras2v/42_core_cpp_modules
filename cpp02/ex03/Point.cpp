#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	#ifdef DEBUG
		std::cout << "Fixed constructor" << std::endl;
	#endif
}

Point::Point( const float x, const float y ) : _x(x), _y(y)
{
	#ifdef DEBUG
		std::cout << "Fixed constructor" << std::endl;
	#endif
}

Point::~Point()
{
	#ifdef DEBUG
		std::cout << "Fixed destructor" << std::endl;
	#endif
}

Point &Point::operator=(const Point &other)
{
	#ifdef DEBUG
		std::cout << "Copy assignment operator called" << std::endl;
	#endif
	if (this != &other)
	{

	}
	return (*this);
}

Point::Point(const Point &other) : _x(other._x.toFloat()), _y(other._y.toFloat())
{
	#ifdef DEBUG
		std::cout << "Copy constructor called" << std::endl;
	#endif
}

Fixed Point::getY() const
{
	return (this->_y);
}

Fixed Point::getX() const
{
	return (this->_x);
}
