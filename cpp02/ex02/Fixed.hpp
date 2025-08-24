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
		Fixed		  &operator=( const Fixed &other );

		float		  toFloat( void ) const;
		int			  toInt( void ) const;

		int			  getRawBits( void ) const;
		void		  setRawBits( int const raw );

		bool		  operator< ( const Fixed &other );
		bool		  operator> ( const Fixed &other );
		bool		  operator<=( const Fixed &other );
		bool		  operator>=( const Fixed &other );
		bool		  operator!=( const Fixed &other );
		bool		  operator==( const Fixed &other );

		Fixed		  operator+( const Fixed &other );
		Fixed		  operator-( const Fixed &other );
		Fixed		  operator*( const Fixed &other );
		Fixed		  operator/( const Fixed &other );

		Fixed		  operator++( int );
		Fixed		  operator--( int );
		Fixed		  operator++( void );
		Fixed		  operator--( void );

		static Fixed  &min( Fixed &lhs, Fixed &rhs );
		static Fixed  &max( Fixed &lhs, Fixed &rhs );
		static const Fixed  &min( const Fixed & lhs, const Fixed & rhs );
		static const Fixed  &max( const Fixed & lhs, const Fixed & rhs );
};

std::ostream& operator<<(std::ostream &ofs, const Fixed &other);

#endif
