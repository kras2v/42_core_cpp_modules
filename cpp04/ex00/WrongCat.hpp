#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <string>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat ( void );
		WrongCat ( const WrongCat &other );
		~WrongCat();

		WrongCat &			operator=( const WrongCat &other );
		void			    makeSound( void ) const;
};

#endif