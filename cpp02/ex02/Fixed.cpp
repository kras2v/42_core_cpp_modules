#include "Fixed.hpp"

const int	Fixed::_numberOfFractionalBit = 8;

Fixed::Fixed()
{
	#ifdef DEBUG
		std::cout << "Fixed constructor" << std::endl;
	#endif
	this->_fixedPointNumberValue = 0;
}

Fixed::~Fixed()
{
	#ifdef DEBUG
		std::cout << "Fixed destructor" << std::endl;
	#endif
}

Fixed::Fixed(const Fixed &other)
{
	#ifdef DEBUG
		std::cout << "Copy constructor called" << std::endl;
	#endif
	*this = other;
}

Fixed::Fixed(const int fixed_point_value) : _fixedPointNumberValue(fixed_point_value)
{
	#ifdef DEBUG
		std::cout << "Int constructor called" << std::endl;
	#endif
}

Fixed::Fixed(const float fixed_point_value)
{
	#ifdef DEBUG
		std::cout << "Float constructor called" << std::endl;
	#endif
	float shifted_fixed_point_value = fixed_point_value * (1 << Fixed::_numberOfFractionalBit);
	this->_fixedPointNumberValue = roundf(shifted_fixed_point_value);
}

Fixed& Fixed::operator=(const Fixed &other)
{
	#ifdef DEBUG
		std::cout << "Copy assignment operator called" << std::endl;
	#endif
	if (this != &other)
	{
		this->_fixedPointNumberValue = other.getRawBits();
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
	return ((float)this->_fixedPointNumberValue / (1 << Fixed::_numberOfFractionalBit));
}

int Fixed::toInt( void ) const
{
	return (this->_fixedPointNumberValue >> Fixed::_numberOfFractionalBit);
}

std::ostream& operator<<(std::ostream &ofs, const Fixed &other)
{
	ofs << (other.toFloat());
	return (ofs);
}

bool	Fixed::operator<( const Fixed &other )
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator<=( const Fixed &other )
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator>( const Fixed &other )
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator>=( const Fixed &other )
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator!=( const Fixed &other )
{
	return (this->getRawBits() != other.getRawBits());
}

bool	Fixed::operator==( const Fixed &other )
{
	return (this->getRawBits() == other.getRawBits());
}

Fixed	Fixed::operator+( const Fixed &other )
{
	Fixed fixed;
	int res = other.getRawBits() + this->getRawBits();
	fixed.setRawBits(res);
	return (fixed);
}

Fixed	Fixed::operator-( const Fixed &other )
{
	Fixed fixed;
	int res = other.getRawBits() - this->getRawBits();
	fixed.setRawBits(res);
	return (fixed);
}

Fixed	Fixed::operator*( const Fixed &other )
{
	Fixed fixed;
	long long res = (long long)other.getRawBits() * (long long)this->getRawBits();
	res = res >> Fixed::_numberOfFractionalBit;
	fixed.setRawBits((int)res);
	return (fixed);
}

Fixed	Fixed::operator/( const Fixed &other )
{
	Fixed fixed;
	int res = ((long long)other.getRawBits() << Fixed::_numberOfFractionalBit) / this->getRawBits();
	fixed.setRawBits(res);
	return (fixed);
}

Fixed	Fixed::operator++( int )
{
	Fixed fixed;
	fixed.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() + 1);
	return (fixed);
}

Fixed	Fixed::operator--( int )
{
	Fixed fixed;
	fixed.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() - 1);
	return (fixed);
}

Fixed	Fixed::operator++( void )
{
	Fixed fixed;
	int res = this->getRawBits() + 1;
	fixed.setRawBits(res);
	this->setRawBits(res);
	return (fixed);
}

Fixed	Fixed::operator--( void )
{
	Fixed fixed;
	int res = this->getRawBits() - 1;
	fixed.setRawBits(res);
	this->setRawBits(res);
	return (fixed);
}

Fixed&	Fixed::min( Fixed &lhs, Fixed &rhs )
{
	return (lhs < rhs ? lhs : rhs);
}

Fixed&	Fixed::max( Fixed &lhs, Fixed &rhs )
{
	return (lhs > rhs ? lhs : rhs);
}

const Fixed&	Fixed::min( const Fixed & lhs, const Fixed & rhs )
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	return (rhs);
}

const Fixed&	Fixed::max( const Fixed & lhs, const Fixed & rhs )
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);
}
