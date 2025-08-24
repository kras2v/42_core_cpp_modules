#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# define ABS(x) (((x) < 0) ? -(x) : (x))

class Point
{
	private:
		const Fixed _x; 
		const Fixed _y; 
	public:
		Point( void );
		Point( const float x, const float y );
		Point &operator=( const Point &other );
		Point( const Point &other );
		~Point( void );

		Fixed getY() const;
		Fixed getX() const;
};

#endif 
