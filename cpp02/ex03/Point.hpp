#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x; 
		const Fixed _y; 
	public:
		Point( );
		Point( const float x, const float y );
		Point &operator=( const Point &other );
		Point( const Point &other );
		~Point( );
};

#endif 
