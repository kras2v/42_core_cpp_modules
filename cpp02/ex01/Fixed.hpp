#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int 				_fixedPointNumberValue;
		static const int	_numberOfFractionalBit;

	public:
		Fixed();
		~Fixed();
		Fixed( const int fixed_point_value );
		Fixed( const float fixed_point_value );
		Fixed( const Fixed &other);

		Fixed	&operator=( const Fixed &other );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream &ofs, const Fixed &other);

#endif
