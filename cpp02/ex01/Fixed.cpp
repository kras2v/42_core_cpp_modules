#include "Fixed.hpp"

const int	Fixed::_numberOfFractionalBit = 8;

Fixed::Fixed()
{
	this->_fixedPointNumberValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int fixed_point_value)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(fixed_point_value << this->_numberOfFractionalBit);
}

Fixed::Fixed(const float fixed_point_value)
{
	std::cout << "Float constructor called" << std::endl;
	float shifted_fixed_point_value = fixed_point_value * (1 << this->_numberOfFractionalBit);
	setRawBits(roundf(shifted_fixed_point_value));
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		setRawBits(other.getRawBits());
	}
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	return (this->_fixedPointNumberValue);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixedPointNumberValue = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_fixedPointNumberValue / (1 << this->_numberOfFractionalBit));
}

int Fixed::toInt( void ) const
{
	return ((int)roundf(this->_fixedPointNumberValue >> this->_numberOfFractionalBit));
}

std::ostream& operator<<(std::ostream &ofs, const Fixed &other)
{
	ofs << (other.toFloat());
	return (ofs);
}
