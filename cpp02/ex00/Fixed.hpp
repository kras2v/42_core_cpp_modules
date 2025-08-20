#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int 				_fixedPointNumberValue;
		static const int	_numberOfFractionalBit;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);

		Fixed	&operator=(const Fixed &other);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
